#ifndef INC_8_22_SHARDINGPROTOCOL_H
#define INC_8_22_SHARDINGPROTOCOL_H

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <vector>

// 单个网络分片的最大总长度，包含消息头和消息体。
constexpr size_t MTU = 1500;

// 每个分片都以该消息头开头。接收方先读取 body_len，才知道还需等待多少字节。
// body_len 使用网络字节序保存，因此发送时用 htonl，接收时用 ntohl 还原。
// htonl 和 ntohl 的声明需要由使用方按平台包含相应的 socket 头文件。
typedef struct
{
    uint32_t body_len; // 不含 Header 自身，只记录本分片消息体的字节数。
} __attribute__((packed)) Header;


// ----------------发送：按 MTU 分片----------------
/// @brief 把一段数据拆成多个分片；每个分片的总长度都不超过 MTU。
/// @return 当前示例没有接入真实 socket，因此始终返回 true；接入后应在发送失败时返回 false。
// data 在 size 大于 0 时必须有效；size 为 0 时不会产生任何分片。
// 该协议只描述“分片”，不记录原始消息总长度和分片序号，接收端不会自动还原原始大消息。
bool send(const char* data, size_t size)
{
    size_t offset = 0;
    // 预留 Header 所占空间后，消息体一次最多可写入的字节数。
    const size_t MAX_BODY_PER_FRAG = MTU - sizeof(Header);

    while(offset < size)
    {
        // 最后一片可能不足最大长度，其余分片都尽量填满。
        size_t frag_body_len = ( (size - offset) > MAX_BODY_PER_FRAG )
                                ? MAX_BODY_PER_FRAG
                                : (size - offset);

        // 构造本次分片：内存布局为 [Header][消息体片段]。
        std::vector<char> pkt(sizeof(Header) + frag_body_len);
        Header* hdr = reinterpret_cast<Header*>(pkt.data());
        hdr->body_len = htonl(static_cast<uint32_t>(frag_body_len));

        // 从原始数据的 offset 位置复制本分片的消息体。
        memcpy(pkt.data() + sizeof(Header), data + offset, frag_body_len);

        // 此处应替换为真实 socket 发送；pkt 只在当前循环内有效。
        // int ret = ::send(fd, pkt.data(), pkt.size(), 0);
        // if(ret <=0) return false;

        // 前进到下一段尚未发送的数据。
        offset += frag_body_len;
    }
    return true;
}


// ----------------接收：处理粘包和半包----------------
// 一个 ReceiverCtx 对应一条连接或一个连续数据流，不能与其他连接混用。
// 若同一上下文会被多个线程调用，调用方需要在外部进行同步。
typedef struct
{
    std::vector<char> buf; // 缓存尚未组成完整分片的字节。
} ReceiverCtx;


/// @brief 底层 socket 每次收到一段原始字节时调用；一次输入可能是半包、整包或多个包。
// ctx、raw_data 必须有效；raw_size 为 0 时仅执行一次无副作用的解析检查。
void on_recv(ReceiverCtx* ctx, const char* raw_data, size_t raw_size)
{
    // 先追加而不是直接解析，因为 TCP 等字节流可能出现粘包和半包。
    ctx->buf.insert(ctx->buf.end(), raw_data, raw_data + raw_size);

    // 每轮消费一个完整分片；循环能够处理一次收到多个分片的情况。
    while(ctx->buf.size() >= sizeof(Header))
    {
        Header* hdr = reinterpret_cast<Header*>(ctx->buf.data());
        uint32_t body_len = ntohl(hdr->body_len);
        // 完整分片长度 = 固定长度的消息头 + 头中声明的消息体长度。
        size_t full_pkt_len = sizeof(Header) + body_len;

        // 消息头完整但消息体尚未收全时，保留缓冲区内容，等待下一次 on_recv。
        if(ctx->buf.size() < full_pkt_len)
        {
            break;
        }

        // 至此拿到一个完整分片的消息体；body_ptr 会在下方 erase 后失效。
        const char* body_ptr = ctx->buf.data() + sizeof(Header);
        // 这里可以交付上层业务；若业务需要异步使用数据，应先自行复制。
        // process_msg(body_ptr, body_len);

        // 删除已消费的分片，保留其后可能已经到达的下一个分片或半包。
        ctx->buf.erase(ctx->buf.begin(), ctx->buf.begin() + full_pkt_len);
    }
}


// 教学示例入口。实际工程中 main 应放在 .cpp 文件，避免头文件被多处包含时重复定义入口。
int main()
{
    ReceiverCtx rx_ctx;
    // 示例尚未接入真实网络数据。
    return 0;
}


#endif //INC_8_22_SHARDINGPROTOCOL_H
