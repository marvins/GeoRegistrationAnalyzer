/**
 * @file    GeoViewerGoogle.hpp
 * @author  Marvin Smith
 * @date    5/5/2017
 */
#ifndef GEOVIEWER_GEOVIEWER_GOOGLE_HPP
#define GEOVIEWER_GEOVIEWER_GOOGLE_HPP


// Qt Libraries
#include <QWidget>

// Project Libraries
#include "../../core/System_Configuration.hpp"
#include "GeoViewerBase.hpp"


/**
 * @class GeoViewerGoogle
 */
class GeoViewerGoogle : public GeoViewerBase
{

public:

    /**
     * @brief Constructor for Google Maps API viewer class
     *
     * @param sys_config
     * @param parent
     */
    GeoViewerGoogle( System_Configuration::ptr_t sys_config,
                     QWidget*                    parent = nullptr );



private:

    /// Class Name
    std::string m_class_name;

};

#endif