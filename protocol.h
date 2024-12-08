#include "protocol_type.h"
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_QUEUE_DEF 10

class protocol
{
private:


private:
    uint8 *m_buffer = NULL;      //最终实际拼接完成的数据
    uint32 m_buffer_size = 0; //当前socket发送实际缓冲区大小
    uint32 m_buffer_max_size = 128; //可以发送的最大长度

    bool m_send_ready_flag = false;//句柄是否准备好发送（接收是否完成）
    bool m_recv_send_flag = false; //当前命令已发送；


    /// @brief 检查数据合法性
    /// @param command 命令
    /// @param command_size 命令大小
    /// @return 
    virtual uint32 m_check_command_legal(void *command,uint32 command_size);


    

public:
    protocol()
    {
        this->m_buffer = new uint8[m_buffer_max_size];
    }
    ~protocol();
    /// @brief 把命令转换为缓冲区数据
    /// @param command 命令
    /// @param buffer 缓存区
    /// @param buffer_size  缓存区大小
    /// @return 
    virtual uint32 m_command_to_buffer(void *command,uint8 **buffer,uint32 *buffer_size); //命令转换为缓冲区数据
};




