PROJECT (QtWidgets)

# Any build configured headers should be added to this 
# variable so that they also get installed.
SET (dynamicHeaders)

INCLUDE_DIRECTORIES(
  ${QtWidgets_SOURCE_DIR}
  ${QtWidgets_BINARY_DIR}
  ${QT_QTDESIGNER_INCLUDE_DIR}
)

## Add the source (*.cxx,*.h) files here.
SET(QtWidgets_SRCS
  pqAnimationKeyFrame.cxx
  pqAnimationKeyFrame.h
  pqAnimationModel.cxx
  pqAnimationModel.h
  pqAnimationTrack.cxx
  pqAnimationTrack.h
  pqAnimationWidget.cxx
  pqAnimationWidget.h
  pqChartPrintSave.cxx
  pqChartPrintSave.h
  pqCheckableHeaderModel.cxx
  pqCheckableHeaderModel.h
  pqCheckableHeaderView.cxx
  pqCheckableHeaderView.h
  pqCheckBoxPixMaps.cxx
  pqCheckBoxPixMaps.h
  pqCollapsedGroup.cxx
  pqCollapsedGroup.h
  pqColorChooserButton.cxx
  pqColorChooserButton.h
  pqColorTableDelegate.cxx
  pqColorTableDelegate.h
  pqColorTableModel.cxx
  pqColorTableModel.h
  pqConnect.cxx
  pqConnect.h
  pqConsoleWidget.cxx
  pqConsoleWidget.h
  pqDelimitedTextParser.cxx
  pqDelimitedTextParser.h
  pqDoubleRangeWidget.cxx
  pqDoubleRangeWidget.h
  pqDoubleSpinBox.cxx
  pqDoubleSpinBox.h
  pqFlatTreeView.cxx
  pqFlatTreeView.h
  pqIntRangeWidget.cxx
  pqIntRangeWidget.h
  pqLineEdit.cxx
  pqLineEdit.h
  pqListWidgetCheckHelper.cxx
  pqListWidgetCheckHelper.h
  pqListWidgetItemObject.cxx
  pqListWidgetItemObject.h
  pqLookmarkToolbar.cxx
  pqLookmarkToolbar.h
  pqProgressBar.cxx
  pqProgressBar.h
  pqProgressBarHelper.h
  pqProgressWidget.cxx
  pqProgressWidget.h
  pqQuickLaunchDialog.cxx
  pqQuickLaunchDialog.h
  pqSectionVisibilityContextMenu.cxx
  pqSectionVisibilityContextMenu.h
  pqSetData.cxx
  pqSetData.h
  pqSetName.cxx
  pqSetName.h
  pqSignalAdaptors.cxx
  pqSignalAdaptors.h
  pqSpinBox.cxx
  pqSpinBox.h
  pqTreeView.cxx
  pqTreeView.h
  pqTreeWidget.cxx
  pqTreeWidget.h
  pqTreeWidgetCheckHelper.cxx
  pqTreeWidgetCheckHelper.h
  pqTreeWidgetItem.cxx
  pqTreeWidgetItem.h
  pqTreeWidgetItemObject.cxx
  pqTreeWidgetItemObject.h
  pqTreeWidgetSelectionHelper.cxx
  pqTreeWidgetSelectionHelper.h
  pqTreeViewSelectionHelper.cxx
  pqTreeViewSelectionHelper.h
  pqViewMenu.cxx
  pqViewMenu.h
  pqWaitCursor.cxx
  pqWaitCursor.h
  pqHelpWindow.cxx
  pqHelpWindow.h
  QtWidgetsExport.h
  QtWidgetsPlugin.cxx
  QtWidgetsPlugin.h
)

IF(Q_WS_MAC)
  SET(QtWidgets_SRCS ${QtWidgets_SRCS} pqProgressBarHelper.mm)
ELSE(Q_WS_MAC)
  SET(QtWidgets_SRCS ${QtWidgets_SRCS} pqProgressBarHelper.cxx)
ENDIF(Q_WS_MAC)

##########################################################################
## Add the header files that need to moc processed.

QT4_WRAP_CPP(QtWidgets_MOC_SOURCES
  QtWidgetsPlugin.h

  pqAnimationKeyFrame.h
  pqAnimationModel.h
  pqAnimationTrack.h
  pqAnimationWidget.h
  pqChartPrintSave.h
  pqCheckableHeaderModel.h
  pqCheckableHeaderView.h
  pqCheckBoxPixMaps.h
  pqCollapsedGroup.h
  pqColorChooserButton.h
  pqColorTableModel.h
  pqConsoleWidget.h
  pqDelimitedTextParser.h
  pqDoubleRangeWidget.h
  pqDoubleSpinBox.h
  pqFlatTreeView.h
  pqIntRangeWidget.h
  pqLineEdit.h
  pqListWidgetCheckHelper.h
  pqListWidgetItemObject.h
  pqLookmarkToolbar.h
  pqProgressBar.h
  pqProgressWidget.h
  pqQuickLaunchDialog.h
  pqSectionVisibilityContextMenu.h
  pqSignalAdaptors.h
  pqSpinBox.h
  pqTreeView.h
  pqTreeWidget.h
  pqTreeWidgetCheckHelper.h
  pqTreeWidgetItemObject.h
  pqTreeWidgetSelectionHelper.h
  pqTreeViewSelectionHelper.h
  pqViewMenu.h
  pqHelpWindow.h
)

##########################################################################
## Add *.ui files to be uic processed.
SET(QtWidgets_UI_FORMS
  Resources/UI/pqQuickLaunchDialog.ui
  Resources/UI/pqHelpWindow.ui
)

QT4_WRAP_UI(QtWidgets_UI_BUILT_SOURCES
  ${QtWidgets_UI_FORMS}
)

##########################################################################
## Add resources.
SET(UI_RESOURCES
  Resources/QtWidgets.qrc
)

QT4_ADD_RESOURCES(RCS_SOURCES
  ${UI_RESOURCES}
)


SOURCE_GROUP("Resources" FILES
  ${UI_RESOURCES}
  ${QtWidgets_UI_FORMS}
)

SOURCE_GROUP("Generated" FILES
  ${QtWidgets_MOC_SOURCES}
  ${RCS_SOURCES}
  ${QtWidgets_UI_BUILT_SOURCES}
)

SET(QT_WIDGETS_ALL_SRCS ${QtWidgets_SRCS} ${QtWidgets_MOC_SOURCES}
  ${RCS_SOURCES} ${QtWidgets_UI_BUILT_SOURCES})

##########################################################################
ADD_LIBRARY(pqWidgets ${QT_WIDGETS_ALL_SRCS})


## Widgets does not depend on VTK/ParaView. Only Qt.
TARGET_LINK_LIBRARIES(pqWidgets
  ${QT_LIBRARIES}
)

SET(QTWIDGETS_BUILD_SHARED_LIBS "${BUILD_SHARED_LIBS}")
CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/QtWidgetsExport.h.in"
               "${CMAKE_CURRENT_BINARY_DIR}/QtWidgetsExport.h")
SET(dynamicHeaders
    "${dynamicHeaders};${CMAKE_CURRENT_BINARY_DIR}/QtWidgetsExport.h")

INSTALL(TARGETS pqWidgets
  RUNTIME DESTINATION ${PV_INSTALL_BIN_DIR} COMPONENT Runtime
  LIBRARY DESTINATION ${PV_INSTALL_LIB_DIR} COMPONENT Runtime
  ARCHIVE DESTINATION ${PV_INSTALL_LIB_DIR} COMPONENT Development)

IF (NOT PV_INSTALL_NO_DEVELOPMENT)
  # Headers
  GLOB_INSTALL_DEVELOPMENT(
      ${CMAKE_CURRENT_SOURCE_DIR}
      ${PV_INSTALL_INCLUDE_DIR} 
      "*.h;*.hxx;*.txx")
  INSTALL(
      FILES ${dynamicHeaders}
      DESTINATION ${PV_INSTALL_INCLUDE_DIR}
      COMPONENT Development)
  # QT resources
  SET(resPath "${CMAKE_CURRENT_SOURCE_DIR}/Resources/UI")
  GLOB_INSTALL_DEVELOPMENT(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${PV_INSTALL_INCLUDE_DIR}/Qt/Widgets/Resources/UI"
    "${resPath}/*.ui")
  SET(resPath "${CMAKE_CURRENT_SOURCE_DIR}/Resources/Icons")
  GLOB_INSTALL_DEVELOPMENT(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${PV_INSTALL_INCLUDE_DIR}/Qt/Widgets/Resources/Icons"
    "${resPath}/*.ico;${resPath}/*.png;${resPath}/*.svg;${resPath}/*.xpm;${resPath}/*.rc")
  SET(resPath "${CMAKE_CURRENT_SOURCE_DIR}/Resources")
  GLOB_INSTALL_DEVELOPMENT(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${PV_INSTALL_INCLUDE_DIR}/Qt/Widgets/Resources"
    "${resPath}/*.ui;${resPath}/*.ico;${resPath}/*.png;${resPath}/*.svg;${resPath}/*.xpm;${resPath}/*.rc;${resPath}/*.qrc")
ENDIF (NOT PV_INSTALL_NO_DEVELOPMENT)

IF(BUILD_TESTING)
  SUBDIRS(Testing)
ENDIF(BUILD_TESTING)
