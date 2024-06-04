//
// Created by KDen404 on 04.04.24.
//

#ifndef OPENGLBASE_FILELOADER_H
#define OPENGLBASE_FILELOADER_H
#include <fstream>
#include <filesystem>
#include <memory>
#include <istream>

namespace Modules {

    class SystemFile {
        typedef std::filesystem::path System_PATH;
    public:
        //Variables
        char* FileBuffer;
        inline static const System_PATH ROOT_PATH = std::filesystem::path(absolute(std::filesystem::current_path()).string() + "/../");
        System_PATH m_Path;
    public:
        SystemFile(System_PATH p_Path) : m_Path(std::filesystem::path(ROOT_PATH.string() + p_Path.string()))
        {
            LoadFromFile();
        };
        ~SystemFile()
        {
            delete[] FileBuffer;
            delete &m_Path;
        };
        inline char* LoadFromFile()
        {
            return RawLoadFromFile(m_Path);
        };
        inline bool SaveToFile(System_PATH p_Path)
        {
            m_Path = std::filesystem::path(ROOT_PATH.string() + p_Path.string());
            FileBuffer = RawLoadFromFile(p_Path);
            return FileBuffer != nullptr;
        };
        inline bool SaveToFile()
        {
            bool success = false;
            std::ofstream file(m_Path);
            if(file.is_open())
            {
                file << FileBuffer;

                success = file.good();
                file.close();
            }

            return success;
        };


    private:
        inline char* RawLoadFromFile(System_PATH p_Path)
        {
            std::ifstream file;
            file.open(p_Path);
            if(file.is_open())
            {
                file.seekg(0, std::ios::end);
                int length = file.tellg();
                file.seekg(0, std::ios::beg);

                FileBuffer = new char[length];
                file.read(FileBuffer, length);
                file.close();
            }

            return FileBuffer;
        };


    };

} // Modules

#endif //OPENGLBASE_FILELOADER_H
