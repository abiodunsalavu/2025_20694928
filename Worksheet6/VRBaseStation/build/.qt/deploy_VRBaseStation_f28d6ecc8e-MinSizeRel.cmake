include("C:/Users/asala/2025_20694928/Worksheet6/VRBaseStation/build/.qt/QtDeploySupport-MinSizeRel.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/VRBaseStation-plugins-MinSizeRel.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE "C:/Users/asala/2025_20694928/Worksheet6/VRBaseStation/build/MinSizeRel/VRBaseStation.exe"
    GENERATE_QT_CONF
)
