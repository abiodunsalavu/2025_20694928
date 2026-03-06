include("C:/Users/asala/2025_20694928/Worksheet7/Exercise 3/VRBaseStation/build/.qt/QtDeploySupport-Release.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/VRBaseStation-plugins-Release.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase;qtdeclarative;qtdeclarative;qtdeclarative;qtdeclarative;qtdeclarative;qtdeclarative;qtdeclarative")

qt6_deploy_runtime_dependencies(
    EXECUTABLE "C:/Users/asala/2025_20694928/Worksheet7/Exercise 3/VRBaseStation/build/Release/VRBaseStation.exe"
    GENERATE_QT_CONF
)
