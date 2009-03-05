#/*=========================================================================
#
#    This file is part of vtkPOpenFOAMReader.
#
#    vtkPOpenFOAMReader is free software: you can redistribute it
#    and/or modify it under the terms of the GNU General Public License
#    as published by the Free Software Foundation, either version 3 of
#    the License, or (at your option) any later version.
#
#    vtkPOpenFOAMReader is distributed in the hope that it will be
#    useful, but WITHOUT ANY WARRANTY; without even the implied
#    warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#    See the GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with vtkPOpenFOAMReader.  If not, see
#    <http://www.gnu.org/licenses/>.
#
#=========================================================================*/
# Copyright (c) 2008 Takuya OSHIMA <oshima@eng.niigata-u.ac.jp>.
# All rights reserved.
# Date: 2008-08-31

IF(PARAVIEW_USE_MPI)

  INCLUDE( ${QT_USE_FILE} )

  INCLUDE_DIRECTORIES(
    ${VTK_INCLUDE_DIR}
    ${PARAVIEW_INCLUDE_DIRS}
    ${PARAVIEW_GUI_INCLUDE_DIRS}
    )

  # Server side

  ADD_PARAVIEW_PLUGIN(
    POpenFOAMReaderSMPlugin "1.0"
    SERVER_MANAGER_XML POpenFOAMReaderSM.xml
    SERVER_MANAGER_SOURCES vtkPOpenFOAMReader.cxx)

  # Client side - no longer necessary!

  # ADD_PARAVIEW_PLUGIN(
  #   POpenFOAMReaderGUIPlugin "1.0"
  #   GUI_RESOURCE_FILES POpenFOAMReaderGUI.xml
  #   )

  # Additional UI elements for the POpenFOAMReader panel

  # SET(MOC_SRCS "")
  QT4_WRAP_CPP(
    MOC_SRCS pqPOpenFOAMPanel.h
    )

  ADD_PARAVIEW_OBJECT_PANEL(
    IFACES IFACE_SRCS
    CLASS_NAME pqPOpenFOAMPanel
    XML_NAME OpenFOAMReader
    XML_GROUP sources
    )

  ADD_PARAVIEW_PLUGIN(
    POpenFOAMPanel "1.0"
    GUI_INTERFACES ${IFACES}
    SOURCES pqPOpenFOAMPanel.cxx
      ${MOC_SRCS} ${RCS_SRCS} ${IFACE_SRCS}
    )

ELSE(PARAVIEW_USE_MPI)

  MESSAGE(FATAL_ERROR "vtkPOpenFOAMReader requires parallelization support.")

ENDIF(PARAVIEW_USE_MPI)
