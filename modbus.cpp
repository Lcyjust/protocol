/*


*/
#include "modbus.h"



namespace modbus
{

    modbus::modbus(MODBUS_COMMAND_ENUM type)
    {
        this->m_modbus_type = type;
    }

    uint32 modbus::m_function_enum_to_function_code(MODBUS_COMMAND_CODE_ENUM function_enum,uint32 *function_code)    
    {
        uint32 result = 0;
        switch (function_enum)
        {
        case MODBUS_COMMAND_CODE_READ_COILS:
            *function_code = 0x01;
            break;
        case MODBUS_COMMAND_CODE_READ_DISCRETE_INPUTS:
            *function_code = 0x02;
            break;
        case MODBUS_COMMAND_CODE_READ_HOLDING_REGISTERS:
            *function_code = 0x03;
            break;
        case MODBUS_COMMAND_CODE_READ_INPUT_REGISTERS:
            *function_code = 0x04;
            break;
        case MODBUS_COMMAND_CODE_WRITE_SINGLE_COIL:
            *function_code = 0x05;
            break;
        case MODBUS_COMMAND_CODE_WRITE_SINGLE_REGISTER:
            *function_code = 0x06;
            break;
        case MODBUS_COMMAND_CODE_WRITE_MULTIPLE_COILS:
            *function_code = 0x0f;
            break;
        case MODBUS_COMMAND_CODE_WRITE_MULTIPLE_REGISTERS:
            *function_code = 0x10;
            break;
        default:
            result = 1;
            break;
        }

        return result;
    }

    uint32 modbus::m_check_command_legal(void *command,uint32 command_size)
    {
        uint32 result = 0;

        if((command == NULL) || (command_size == 0)||(command_size != sizeof(MODBUS_COMMAND_STRUCT)))
        {
            result = 1;
        }
        
        //检查地址合法
        if(result == 0)
        {
            if(((MODBUS_COMMAND_STRUCT *)command)->modbus_command_mid.slave_address > 
                                        MODBUS_SLAVER_ID_MAX_DEF)
            {
                result = 1;
            }
        }

        return result;
    }
    


    uint32 modbus::m_command_to_buffer(void *command, uint8 **buffer,uint32 *buffer_size)
    {
        uint32 result = 0;

        MODBUS_COMMAND_STRUCT modbus_command;
        memset(&modbus_command,0,sizeof(MODBUS_COMMAND_STRUCT));


        //拼接socket字符
        if(result == 0)
        {
            switch(this->m_modbus_type)
            {
                case MODBUS_COMMAND_RTU:
    
                    break;
                case MODBUS_COMMAND_TCP:

                    break;
                default:
                    break;
            }
        }
        
        return result;
    }




}