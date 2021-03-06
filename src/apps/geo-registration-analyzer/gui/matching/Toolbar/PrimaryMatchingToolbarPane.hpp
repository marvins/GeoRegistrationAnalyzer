/**
 * @file    PrimaryMatchingToolbarPane.hpp
 * @author  Marvin Smith
 * @date    5/19/2017
 */
#ifndef GUI_MATCHING_TOOLBAR_PRIMARYMATCHINGTOOLBARPANE_HPP
#define GUI_MATCHING_TOOLBAR_PRIMARYMATCHINGTOOLBARPANE_HPP

// C++ Libraries
#include <map>
#include <string>


// Qt Libraries
#include <QGridLayout>
#include <QLabel>
#include <QToolButton>
#include <QWidget>


// GeoViewer Libraries
#include <GeoViewer/core/System_Configuration.hpp>


/**
 * @class PrimaryMatchingToolbarPane
 */
class PrimaryMatchingToolbarPane : public QWidget
{
    Q_OBJECT

    public:

        /**
         * @brief Constructor
         * @param sys_config
         * @param parent
         */
        PrimaryMatchingToolbarPane( System_Configuration::ptr_t sys_config,
                                    QWidget*                    parent = nullptr );


    signals:

        /**
         * @brief Notify the back button was pressed.
         */
        void Notify_Change_Panel( int );


    protected:

        /**
         * @brief Initialize the GUI
         */
        void Initialize_GUI();


    private slots:

        /**
         * @brief Process the Project Button
         */
        void Project_Button_Pressed();


    private:

        /**
         * @brief Initialize the Configuration
         */
        void Initialize_Configuration();


        /**
         * @brief Build Label
         */
        void Build_Title_Widget();


        /**
         * @brief Build Tool Buttons
         */
        void Build_Tool_Buttons();


        /// Class name
        std::string m_class_name;

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

        /// main layout
        QGridLayout* m_main_layout;

        /// List of Buttons (Key is Sys-Config Element Name, Value is button reference)
        std::map<std::string,QToolButton*> m_button_list;

};

#endif