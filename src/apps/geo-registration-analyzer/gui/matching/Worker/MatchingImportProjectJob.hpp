/**
 * @file    MatchingImportProjectJob.hpp
 * @author  Marvin Smith
 * @date    5/12/2017
 */
#ifndef GUI_MATCHING_WORKER_MATCHING_IMPORT_PROJECT_JOB_HPP
#define GUI_MATCHING_WORKER_MATCHING_IMPORT_PROJECT_JOB_HPP

// Project Libraries
#include <GeoViewer/core/Config_Param.hpp>
#include <GeoViewer/core/System_Configuration.hpp>
#include <GeoViewer/core/Thread_Pool.hpp>


/**
 * @class MatchingImportProjectJob
 */
class MatchingImportProjectJob : public Worker_Thread
{
    public:

        /**
         * @brief Constructor
         */
        MatchingImportProjectJob( const Config_Param&          project_info,
                                  System_Configuration::ptr_t  sys_config );


        /**
         * @brief Execute the job
         */
        virtual int Execute();


    private:

        /**
         * @brief  Build Image Asset
         */
        void Build_Image_Asset( const std::string& panel_type,
                                const std::string& base_element )const;


        /// Class Name
        std::string m_class_name;

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

        /// Project Info
        Config_Param m_project_info;
};


#endif