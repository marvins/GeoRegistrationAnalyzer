/**
 * @file    Asset_Manager_Widget.hpp
 * @date    8/7/2017
 * @author  Marvin Smith
 */
#ifndef GEO_VIEWER_GUI_WIDGETS_ASSET_MANAGER_WIDGET_HPP
#define GEO_VIEWER_GUI_WIDGETS_ASSET_MANAGER_WIDGET_HPP


// Qt Libraries
#include <QGroupBox>
#include <QHBoxLayout>
#include <QToolButton>
#include <QTreeWidget>
#include <QWidget>

// Project Libraries
#include "../dialogs/import_asset/ImportAssetDialog.hpp"

// GeoViewer Libraries
#include <GeoViewer/core/System_Configuration.hpp>

// C++ Libraries
#include <vector>


/**
 * @class Asset_Manager_Widget
 */
class Asset_Manager_Widget : public QGroupBox
{
    Q_OBJECT

    signals:

        /**
         * @brief Notify that Asset is Ready for Import
         */
        void Asset_Ready_To_Import();

    public:

        /**
         * @brief Constructor
         * @param sys_config
         * @param parent
         */
        Asset_Manager_Widget( System_Configuration::ptr_t sys_config,
                              QWidget*                    parent = nullptr );


        /**
         * @brief Handler Message
         */
        void Handle_Message( const std::string& topic_name,
                             const std::string& message );

    public slots:

        /**
         * @brief Add Layer
         */
        void Trigger_Import_Asset_Response();


        /**
         * @brief Update Tree
         */
        void Add_Asset_Element( const int& asset_id );

    private:

        /**
         * @brief Initialize the GUI
         */
        void Initialize_GUI();

        /**
         * @brief Build the Tree Widget
         */
        void Build_Tree_Widget();


        /**
         * @brief Build the Toolbar
         */
        void Build_Toolbar();


        /**
         * @brief Build Sub-Dialogs
         */
        void Build_Dialogs();


        /**
         * @brief Initialize Configuration
         */
        void Initialize_Configuration();

        /// Class Name
        std::string m_class_name;

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

        /// Main Layout
        QHBoxLayout* m_main_layout;

        /// Asset Tree
        QTreeWidget* m_asset_widget;

        /// Button List
        std::vector<QToolButton*> m_tool_buttons;

        /// Import Asset Dialog
        ImportAssetDialog* m_import_asset_dialog;

        /// Asset Elements
        std::map<int,QTreeWidgetItem*> m_registered_assets;

}; // End of Asset_Manager_Widget Class

#endif