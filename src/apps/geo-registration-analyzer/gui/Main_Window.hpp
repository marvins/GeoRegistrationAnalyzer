/**
 * @file    Main_Window.hpp
 * @author  Marvin Smith
 * @date    4/21/2017
 */
#ifndef GEO_REGISTRATION_UTILITY_GUI_MAIN_WINDOW_HPP
#define GEO_REGISTRATION_UTILITY_GUI_MAIN_WINDOW_HPP

// C++ Libraries
#include <map>
#include <string>

// Qt Libraries
#include <QMainWindow>
#include <QStackedWidget>

// GeoViewer Libraries
#include <GeoViewer/core/System_Configuration.hpp>


// Project Libraries
#include "project_dialogs/NewProjectDialog.hpp"
#include "project_dialogs/ImportProjectDialog.hpp"
#include "PreferenceDialog.hpp"
#include "analysis/AnalysisBasePanel.hpp"
#include "matching/MatchingBasePanel.hpp"


/**
 * @class Main_Window
 */
class Main_Window : public QMainWindow
{
    Q_OBJECT

    public:

        /**
         * @brief Constructor
         */
        Main_Window( System_Configuration::ptr_t  system_configuration,
                     QWidget*                     parent = nullptr );


        /**
         * @brief Load the Project
         */
        void Load_Project( const std::string& project_pathname );


    protected:

        /**
         * @brief Initialize GUI
        */
        void Initialize_GUI();

        /**
         * @brief Close the GUI
         *
         * @param event
         */
        void closeEvent(QCloseEvent *event);


    protected slots:

        /**
         * @brief Create New Project
         */
        void New_Project_Dialog();


        /**
         *  @brief Load the Project GUI
         */
        void Import_Project_Dialog();

    private:

        /**
         * @brief Update Configuration
         */
        void Update_Configuration();


        /**
         * @brief Build Menu
         */
        void Build_Menu();


        /// Class Name
        std::string m_class_name;

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

        /// Main Widget Stack
        QStackedWidget* m_stack_widget;

        /// Preferences Dialog
        PreferenceDialog* m_pref_dialog;

        /// New Project Dialog
        NewProjectDialog*    m_new_project_dialog;

        /// Import Project Dialog
        ImportProjectDialog* m_import_project_dialog;

        /// Project Panels
        std::map<std::string,ProjectBasePanel*> m_project_panels;

}; // End of Main_Window Class

#endif
