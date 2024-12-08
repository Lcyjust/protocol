#ifndef MODBUS_H

#include "protocol.h"


namespace modbus
{

   


   


    //----------------------------类结构------------------------------//
class modbus:public protocol
{
private:
    //----------------------------数据宏定义------------------------------//
    
    #define MODBUS_SLAVER_ID_MAX_DEF           128 //最大从站支持


    //----------------------------数据别名------------------------------//
    
     //----------------------------数据枚举------------------------------//
    
    typedef enum{
        MODBUS_COMMAND_MIN =0,

        MODBUS_COMMAND_RTU = 1,
        MODBUS_COMMAND_TCP = 2,

        MODBUS_COMMAND_MAX
    }MODBUS_COMMAND_ENUM;// 定义Modbus类型枚举



    
    typedef enum{
        MODBUS_COMMAND_CODE_READ_COILS = 1,       // 读取线圈状态
        MODBUS_COMMAND_CODE_READ_DISCRETE_INPUTS = 2, // 读取离散输入状态
        MODBUS_COMMAND_CODE_READ_HOLDING_REGISTERS = 3, // 读取保持寄存器
        MODBUS_COMMAND_CODE_READ_INPUT_REGISTERS = 4, // 读取输入寄存器
        MODBUS_COMMAND_CODE_WRITE_SINGLE_COIL = 5, // 写单个线圈
        MODBUS_COMMAND_CODE_WRITE_SINGLE_REGISTER = 6, // 写单个寄存器
        MODBUS_COMMAND_CODE_WRITE_MULTIPLE_COILS = 7,//15,写多个线圈
        MODBUS_COMMAND_CODE_WRITE_MULTIPLE_REGISTERS = 8,//16写多个寄存器

        MODBUS_COMMAND_CODE_MAX,
    }MODBUS_COMMAND_CODE_ENUM;// 定义Modbus功能码枚举

    //----------------------------数据结构------------------------------//
    typedef struct _modbus_slaver_id{
        uint32_t slaver_id;
    }MODBUS_SLAVER_ID_STRUCT;


    typedef struct _modbus_command_mid
    {
        uint32_t slave_address;
        uint32_t function_code;
        uint32_t starting_address;
        uint32_t quantity;
    }MODBUS_COMMAND_MID_STRUCT;//tcp和rtu共有的部分

    typedef struct _modbus_command_tcp_head
    {
        uint32_t transaction_id;
        uint32_t protocol_id;
        uint32_t length;
    }MODBUS_COMMAND_TCP_HEAD_STRUCT;//tcp

    typedef struct _modbus_command_rtu_end
    {
        uint32_t crc;
    }MODBUS_COMMAND_RTU_END_STRUCT;//rtu

    typedef struct _modbus_command 
    {
        MODBUS_COMMAND_TCP_HEAD_STRUCT  modbus_tcp_comand_head;
        MODBUS_COMMAND_MID_STRUCT       modbus_command_mid;
        MODBUS_COMMAND_RTU_END_STRUCT   modbus_command_rtu_end;
    }MODBUS_COMMAND_STRUCT;//modbus command
    /* data */
    modbus(MODBUS_COMMAND_ENUM type);
    ~modbus();


    MODBUS_SLAVER_ID_STRUCT m_slaver_id;
    MODBUS_COMMAND_ENUM m_modbus_type;


    uint32 m_check_command_legal(void *command,uint32 command_size) override;
    uint32 m_function_enum_to_function_code(MODBUS_COMMAND_CODE_ENUM function_enum,uint32 *function_code) ;

public:
    uint32 m_command_to_buffer(void *command,uint8 **buffer,uint32 *buffer_size) override;

    };






}







#endif // MODBUS_H