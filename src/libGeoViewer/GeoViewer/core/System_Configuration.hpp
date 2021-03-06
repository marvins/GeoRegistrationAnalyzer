/**
 *  @file    System_Configuration.hpp
 *  @author  Marvin Smith
 *  @date    4/21/2017
 */
#ifndef LIB_GEO_CORE_SYSTEM_CONFIGURATION_HPP
#define LIB_GEO_CORE_SYSTEM_CONFIGURATION_HPP

// C++ Libraries
#include <map>
#include <memory>
#include <string>

// Project Libraries
#include "Config_Param.hpp"


/**
 * @class Default_Config_Generator
 */
class Default_Config_Generator
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<Default_Config_Generator> ptr_t;


        /**
         * @brief Generate Default Configuration Options.
         * @return
         */
        virtual Config_Param Generate() = 0;
};

/**
 * @class System_Configuration
 */
class System_Configuration
{
    public:
        
        /// Pointer Type
        typedef std::shared_ptr<System_Configuration> ptr_t;


        /**
         * @brief Constructor
         */
        System_Configuration( int argc,
                              char* argv[],
                              Default_Config_Generator::ptr_t );


        /**
         * @brief Finalize
         */
        void Finalize();


        /**
         * @brief Get the Config Pathname
         * @return Config File Pathname
         */
        inline std::string Get_Configuration_File_Pathname()const{
            return m_config_pathname;
        }


        /**
         * @brief Get the Icon Path
         */
         std::string Get_Icon_Path();


        /**
         * @brief Get the HTML Path
         *
         */
        std::string Get_HTML_Path();


        /**
         * @brief Get Configuration Params
         *
         * @return Config Params
         */
        inline Config_Param Get_Config_Params()const{
            return m_config_params;
        };


        /**
         * @brief Add Configuration Option
         */
        void Add_Config_Param( const std::string& key_name,
                               const std::string& value,
                               const std::string& comment = "" ,
                               const bool&        override = false );


        /**
         * @brief Query Configuration Option
         */
        std::string Query_Config_Param( const std::string& key_name,
                                        bool&              value_found ) const;


        /**
         * @brief Query Configuration Option
         */
        std::string Query_Config_Param( const std::string& key_name,
                                        bool&              value_found,
                                        const std::string& default_value = "",
                                        const bool&        write_if_not_found = false );


        /**
         * @brief Query Configuration Option
         */
        std::string Query_Config_Param_NL( const std::string& key_name,
                                           bool&              value_found,
                                           const std::string& default_value = "",
                                           const bool&        write_if_not_found = false );

        /**
         * @brief Query Configuration Option
         */
        int Query_Config_Param_Int32( const std::string& key_name,
                                      bool&              value_found,
                                      const int&         default_value = 0,
                                      const bool&        write_if_not_found = false );


        /**
         * @brief Check if File Exists
         */
        bool Config_File_Path_Exists()const;


        /**
         * @brief Generate the Configuration File
         */
        void Generate_Configuration_File();


        /**
         * @brief Check for system changes.
         */
        bool Has_Changed()const;


        /**
         * @brief Get the configuration list
         * @return
         */
        std::map<std::string,std::string> Get_Config_List()const;


        inline bool Project_Path_Provided()const{
            return m_project_pathname_provided;
        }


        /**
         * @brief Get the Project Path
         * @return
         */
        inline std::string Get_Project_Pathname()const{
            return m_project_pathname;
        }

    protected:

        /**
         * @brief Set Default Values
         */
        void Set_Defaults();


        /**
         * @brief Build the Project Structure
         */
        void Build_Project_Structure();


        /**
         * @brief Parse the Command-Line
         *
         * @param[in] argv
         * @param[in] argc
         */
        void Parse_Command_Line( int argc, char* argv[] );


        /**
         * @brief Parse the Configuration File
         */
        void Parse_Configuration_File();


    private:

        /// Class Name
        std::string m_class_name;

        /// Application Name
        std::string m_application_name;

        /// Default Configuration Generator
        Default_Config_Generator::ptr_t m_config_generator;

        /// Configuration File Path
        std::string m_config_pathname;

        /// Configuration Parameters
        Config_Param m_config_params;

        /// Project Path Notes
        std::string m_project_pathname;
        bool m_project_pathname_provided;


}; // End of System_Configuration Class


#endif
