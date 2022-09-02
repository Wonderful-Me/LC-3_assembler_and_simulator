/*
 * @Author       : Chivier Humber
 * @Date         : 2021-09-15 21:15:24
 * @LastEditors  : Chivier Humber
 * @LastEditTime : 2021-11-23 16:08:51
 * @Description  : file content
 */
#include "common.h"
#include "memory.h"

namespace virtual_machine_nsp {
    void memory_tp::ReadMemoryFromFile(std::string filename, int beginning_address) {
        // Read from the file
        // TO BE DONE
        std::ifstream input_file(filename);
        std::string line;
        int current_address = beginning_address;
        
        if (input_file.is_open()) {
            while (std::getline(input_file, line)) {
                memory[current_address] = 0;
                for (auto it: line) {
                    memory[current_address] <<= 1;
                    if (it == '1') memory[current_address] += 1;
                }
                ++current_address;
            }
        } else {
            std::cout << "Unable to open file" << std::endl;
            // @ Input file read error
            return;
        }
    }

    int16_t memory_tp::GetContent(int address) const {
        // get the content
        // TO BE DONE
        return memory[address];
    }

    int16_t &memory_tp::operator[](int address) {
        // get the content
        // TO BE DONE
        return memory[address];
    }    
}; // virtual machine namespace
