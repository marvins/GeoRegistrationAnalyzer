/**
 * @file     ProjectViewer.cpp
 * @author   Marvin Smith
 * @date     8/6/2017
 */
#include "ProjectViewer.hpp"


// Qt Libraries
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QToolButton>


/*********************************/
/*          Constructor          */
/*********************************/
ProjectViewer::ProjectViewer( const Config_Param&          project_info,
                              System_Configuration::ptr_t  sys_config,
                              QWidget*                     parent)
  : QWidget(parent),
    m_class_name("ProjectViewer"),
    m_project_info(project_info),
    m_sys_config(sys_config)
{
    // Initialize the Configuration
    Initialize_Configuration();

    // Initialize the GUI
    Initialize_GUI();
}


/************************************/
/*          Initialize GUI          */
/************************************/
void ProjectViewer::Initialize_GUI()
{
    // Create the main layout
    m_main_layout = new QVBoxLayout();

    // Create the label
    Build_Title_Widget();

    // Set the layout
    setLayout(m_main_layout);
}


/***********************************************/
/*          Initialize Configuration           */
/***********************************************/
void ProjectViewer::Initialize_Configuration()
{

}

/**************************************/
/*          Build the Label           */
/**************************************/
void ProjectViewer::Build_Title_Widget()
{
    bool value_found;
    std::string project_id   = m_project_info.Query_KV_Pair("project.id", value_found);
    std::string project_name = m_project_info.Query_KV_Pair("project.name", value_found);

    // Create the main widget
    QWidget* widget = new QWidget(this);

    // Build the layout
    QGridLayout*  layout = new QGridLayout();

    // Set label
    QLabel*  project_label = new QLabel("Project Type:");
    layout->addWidget(project_label, 0, 0, 1, 1);

    QLineEdit* project_edit = new QLineEdit("Matching");
    project_edit->setReadOnly(true);
    layout->addWidget(project_edit, 0, 1, 1, 1);

    // Set label
    QLabel*  project_name_label = new QLabel("Project Name:");
    layout->addWidget(project_name_label, 1, 0, 1, 1);

    QLineEdit* project_name_edit = new QLineEdit(project_name.c_str());
    project_edit->setReadOnly(true);
    layout->addWidget(project_name_edit, 1, 1, 1, 1);

    // Set label
    QLabel*  project_id_label = new QLabel("Project ID:");
    layout->addWidget(project_id_label, 2, 0, 1, 1);

    QLineEdit* project_id_edit = new QLineEdit(project_id.c_str());
    project_edit->setReadOnly(true);
    layout->addWidget(project_id_edit, 2, 1, 1, 1);

    // Set the layout
    widget->setLayout(layout);

    // Add to main layout
    m_main_layout->addWidget(widget);
}
