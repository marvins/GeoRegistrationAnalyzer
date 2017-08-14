/**
 * @file    ImportAssetEasyWidget.cpp
 * @author  Marvin Smith
 * @date    8/12/2017
 */
#include "ImportAssetEasyWidget.hpp"

// GeoViewer Libraries
#include <GeoViewer/core/assets.hpp>
#include <GeoViewer/core/System_Manager.hpp>
#include <GeoViewer/log/System_Logger.hpp>

// Qt Libraries
#include <QFileDialog>
#include <QGroupBox>
#include <QToolButton>


/********************************/
/*          Constructor         */
/********************************/
ImportAssetEasyWidget::ImportAssetEasyWidget(System_Configuration::ptr_t sys_config,
                                             QWidget*                    parent)
{
    // Initialize the GUI
    Initialize_GUI();
}


/****************************************/
/*               Reset Action           */
/****************************************/
void ImportAssetEasyWidget::Reset_Action()
{
    //  Reset Path Label
    m_path_label->setText("None Selected");

    // Reset Info Panel
    auto new_panel = new QLabel("No Asset Selected");
    Replace_Info_Panel(new_panel);

}


/****************************************/
/*          Select File to Import       */
/****************************************/
void ImportAssetEasyWidget::Select_File_Action()
{
    // Setup File Selector
    QFileDialog selector( this, "Select Asset to Import", "~/");
    selector.setViewMode(QFileDialog::ViewMode::Detail);

    // Show
    QStringList file_list;
    if( selector.exec() )
    {
        // Make sure file is good
        file_list = selector.selectedFiles();

        if( file_list.size() == 1 )
        {
            if( QFile(file_list[0]).exists() )
            {
                // Try to parse the file
                Check_Asset_Info(file_list[0].toStdString());
            }
        }
    }

    // Get results
}


/********************************/
/*          Initialize GUI      */
/********************************/
void ImportAssetEasyWidget::Initialize_GUI()
{

    // Create Layout
    m_main_layout = new QVBoxLayout();
    m_main_layout->setAlignment(Qt::AlignTop);


    // Create the Path Widget
    Build_Path_Widget();

    // Build the Info Widget
    Build_Info_Widget();

    // Set the Main Layout
    setLayout(m_main_layout);
}


/***********************************************/
/*             Build Path Widget               */
/***********************************************/
void ImportAssetEasyWidget::Build_Path_Widget()
{
    //  Create Path Widget
    QGroupBox*   path_widget = new QGroupBox("Path Information");
    QHBoxLayout* path_layout = new QHBoxLayout();

    // Create Path Label
    m_path_label = new QLabel("None Selected");
    m_path_label->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    m_path_label->setFixedHeight(10);
    path_layout->addWidget(m_path_label);


    // Create Selection Button
    QToolButton* path_button = new QToolButton();
    path_button->setText("Select");
    path_layout->addWidget(path_button);
    connect(path_button, SIGNAL(clicked()), this, SLOT(Select_File_Action()));


    path_widget->setLayout(path_layout);
    m_main_layout->addWidget(path_widget);
}


/***********************************************/
/*          Build Information Widget           */
/***********************************************/
void ImportAssetEasyWidget::Build_Info_Widget()
{
    //  Create Placeholder Widget
    m_info_panel = new QLabel("No Asset Selected");
    m_main_layout->addWidget(m_info_panel);
}

/************************************************************/
/*          Check the Asset and Create Info Pane            */
/************************************************************/
void ImportAssetEasyWidget::Check_Asset_Info( const std::string& asset_path )
{
    // Log Entry
    LOG_CLASS_TRACE("Start of Method. Path: " + asset_path);

    // Initialize Status
    Status status = Status::SUCCESS();
    Status temp_status = Status::SUCCESS();

    // Check file extension


    // If everything good, update label
    m_path_label->setText( asset_path.c_str() );

    // Process Contents
    bool successful;
    std::string error_msg;
    Config_Param asset_info = Asset_Loader::Load_Asset_Info( asset_path,
                                                             temp_status );
    status.Append(temp_status);

    // Check Contents
    if( status.Not_Failure() )
    {
        // Display Error Widget
        QString qmsg = "Error: Unsupported Dialog.\nDetails: ";
        qmsg += status.To_Log_String().c_str();
        auto new_panel = new QLabel(qmsg);
        Replace_Info_Panel( new_panel );
    }

    // Otherwise, Process Widget
    else
    {
        // Load the Asset
        Asset_Base::ptr_t new_asset = Asset_Loader::Load_Asset( asset_info,
                                                                temp_status );
        status.Append(temp_status);

        // Make sure successful
        if( !status.Not_Failure() )
        {
            QString qmesg = "Unable to load asset. Asset Info: ";
            qmesg += asset_info.ToString().c_str();
            qmesg += "\n Error Message: ";
            qmesg += status.To_Log_String().c_str();

            auto new_panel = new QLabel(qmesg);
            Replace_Info_Panel(new_panel);

        }

        // Continue
        else
        {
            //System_Manager::Get_Message_Service()
        }

    }


}


/************************************************************/
/*          Replace Easy Import Information Panel           */
/************************************************************/
void ImportAssetEasyWidget::Replace_Info_Panel( QWidget* widget )
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Make sure info panel is not null
    if( m_info_panel != nullptr )
    {
        // Remove old widget
        m_main_layout->removeWidget(m_info_panel);
        delete m_info_panel;
        m_info_panel = nullptr;
    }

    // Replace Panel
    m_info_panel = widget;
    m_main_layout->addWidget(m_info_panel);

    // Log Exit
    LOG_CLASS_EXIT();
}