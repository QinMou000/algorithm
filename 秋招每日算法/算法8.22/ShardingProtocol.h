#ifndef INC_8_22_SHARDINGPROTOCOL_H
#define INC_8_22_SHARDINGPROTOCOL_H

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <vector>

constexpr size_t MTU = 1500;

// 消息头：记录消息体长度，packed关闭内存对齐
typedef struct
{
    uint32_t body_len; // 网络字节序！消息体字节数
} __attribute__((packed)) Header;


// ----------------发送：send 实现（分片，不超过MTU；上层调用）----------------
/// @brief 发送，超过MTU就分片；每个分片都带Header
bool send(const char* data, size_t size)
{
    size_t offset = 0;
    const size_t MAX_BODY_PER_FRAG = MTU - sizeof(Header);

    while(offset < size)
    {
        size_t frag_body_len = ( (size - offset) > MAX_BODY_PER_FRAG )
                                ? MAX_BODY_PER_FRAG
                                : (size - offset);

        // 构造分片包：Header + body片段
        std::vector<char> pkt(sizeof(Header) + frag_body_len);
        Header* hdr = reinterpret_cast<Header*>(pkt.data());
        hdr->body_len = htonl(static_cast<uint32_t>(frag_body_len));

        memcpy(pkt.data() + sizeof(Header), data + offset, frag_body_len);

        // 这里替换成真正socket发送，示例直接模拟成功
        // int ret = ::send(fd, pkt.data(), pkt.size(), 0);
        // if(ret <=0) return false;

        offset += frag_body_len;
    }
    return true;
}


// ----------------接收上下文：处理粘包半包 ----------------
typedef struct
{
    std::vector<char> buf; // 接收缓冲区，缓存不完整消息
} ReceiverCtx;


/// @brief on_recv:底层socket收到raw_data就调用这个回调
void on_recv(ReceiverCtx* ctx, const char* raw_data, size_t raw_size)
{
    // 1.把新收到字节追加到缓冲区
    ctx->buf.insert(ctx->buf.end(), raw_data, raw_data + raw_size);

    // 循环解包：只要缓冲区足够一个完整Header就尝试解析
    while(ctx->buf.size() >= sizeof(Header))
    {
        Header* hdr = reinterpret_cast<Header*>(ctx->buf.data());
        uint32_t body_len = ntohl(hdr->body_len);
        size_t full_pkt_len = sizeof(Header) + body_len;

        // 还没收完完整包（半包），退出等后续数据
        if(ctx->buf.size() < full_pkt_len)
        {
            break;
        }

        // 拿到完整消息体
        const char* body_ptr = ctx->buf.data() + sizeof(Header);
        // =========这里就是一条完整消息，可以交付上层业务=========
        // process_msg(body_ptr, body_len);

        // 从缓冲区移除已经消费完的数据包
        ctx->buf.erase(ctx->buf.begin(), ctx->buf.begin() + full_pkt_len);
    }
}


int main()
{
    ReceiverCtx rx_ctx;
    // demo示意
    return 0;
}


#endif //INC_8_22_SHARDINGPROTOCOL_H