# Define minimum supported Windows version
# https://msdn.microsoft.com/en-us/library/6sehtctf.aspx
#
# Currently set to Windows 7
add_definitions(-D_WINDOWS -DWINVER=0x601 -D_WIN32_WINNT=0x601)

add_definitions(-DNOMINMAX)
add_definitions(-DUNICODE -D_UNICODE)

if ((NOT DEFINED ENABLE_HFCL_LEGACY) OR ENABLE_HFCL_LEGACY)
    set(ENABLE_HFCL_LEGACY ON)
    set(ENABLE_HFCL OFF)
endif ()

HFCL_OPTION_BEGIN()

HFCL_OPTION_DEFINE(USE_VERSION_STAMPER "Toggle stamping version information during build" PRIVATE OFF)

# FIXME: Most of these options should not be public.
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_3D_TRANSFORMS PUBLIC ON)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_ACCELERATED_2D_CANVAS PUBLIC OFF)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_OVERFLOW_SCROLLING_TOUCH PUBLIC OFF)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_API_TESTS PUBLIC ON)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_ATTACHMENT_ELEMENT PUBLIC ON)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_CHANNEL_MESSAGING PUBLIC ON)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_CSS3_TEXT PUBLIC OFF)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_CSS_BOX_DECORATION_BREAK PUBLIC ON)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_CSS_COMPOSITING PUBLIC OFF)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_CSS_SELECTORS_LEVEL4 PUBLIC ON)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_CURSOR_VISIBILITY PUBLIC ON)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_CUSTOM_SCHEME_HANDLER PUBLIC OFF)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_DATALIST_ELEMENT PUBLIC OFF)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_DEVICE_ORIENTATION PUBLIC OFF)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_DRAG_SUPPORT PUBLIC ON)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_FETCH_API PUBLIC ON)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_FTL_JIT PUBLIC OFF)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_FULLSCREEN_API PUBLIC ON)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_GAMEPAD PUBLIC OFF)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_GEOLOCATION PUBLIC ON)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_ICONDATABASE PUBLIC ON)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_INDEXED_DATABASE PUBLIC ON)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_INDEXED_DATABASE_IN_WORKERS PUBLIC ON)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_INPUT_TYPE_COLOR PUBLIC OFF)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_INPUT_TYPE_DATE PUBLIC OFF)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_INPUT_TYPE_DATETIME_INCOMPLETE PUBLIC OFF)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_INPUT_TYPE_DATETIMELOCAL PUBLIC OFF)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_INPUT_TYPE_MONTH PUBLIC OFF)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_INPUT_TYPE_TIME PUBLIC OFF)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_INPUT_TYPE_WEEK PUBLIC OFF)
if (${WTF_CPU_X86})
    HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_JIT PUBLIC OFF)
endif ()
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_LEGACY_CSS_VENDOR_PREFIXES PUBLIC ON)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_MATHML PUBLIC ON)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_MEDIA_CONTROLS_SCRIPT PUBLIC ON)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_MEDIA_SOURCE PUBLIC OFF)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_MEDIA_STATISTICS PUBLIC ON)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_METER_ELEMENT PUBLIC ON)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_MOUSE_CURSOR_SCALE PUBLIC ON)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_NOTIFICATIONS PUBLIC OFF)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_QUOTA PUBLIC OFF)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_STREAMS_API PUBLIC ON)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_SVG_FONTS PUBLIC ON)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_VIDEO PUBLIC ON)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_VIDEO_TRACK PUBLIC ON)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_WEBASSEMBLY PRIVATE OFF)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_WEB_AUDIO PUBLIC OFF)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_XSLT PUBLIC ON)

HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_SMOOTH_SCROLLING PRIVATE OFF)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_USER_MESSAGE_HANDLERS PRIVATE OFF)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_USERSELECT_ALL PRIVATE OFF)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_WEBGL PRIVATE OFF)
HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_WEB_CRYPTO PRIVATE OFF)

# FIXME: Port bmalloc to Windows. https://bugs.webkit.org/show_bug.cgi?id=143310
HFCL_OPTION_DEFAULT_PORT_VALUE(USE_SYSTEM_MALLOC PRIVATE ON)

if (${WTF_PLATFORM_WIN_CAIRO})
    HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_LEGACY_CUSTOM_PROTOCOL_MANAGER PUBLIC OFF)
    HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_LEGACY_ENCRYPTED_MEDIA PUBLIC OFF)
    HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_INTL PUBLIC ON)
    HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_PUBLIC_SUFFIX_LIST PRIVATE ON)
    HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_WEBGL PUBLIC ON)

    # Experimental features
    HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_APPLICATION_MANIFEST PRIVATE ${ENABLE_EXPERIMENTAL_FEATURES})
    HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_FILTERS_LEVEL_2 PRIVATE ${ENABLE_EXPERIMENTAL_FEATURES})
    HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_CSS_PAINTING_API PRIVATE ${ENABLE_EXPERIMENTAL_FEATURES})
    HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_CSS_TYPED_OM PRIVATE ${ENABLE_EXPERIMENTAL_FEATURES})
    HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_RESOURCE_LOAD_STATISTICS PRIVATE ${ENABLE_EXPERIMENTAL_FEATURES})
    HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_SERVICE_WORKER PRIVATE ${ENABLE_EXPERIMENTAL_FEATURES})
    HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_VARIATION_FONTS PRIVATE ${ENABLE_EXPERIMENTAL_FEATURES})
    HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_REMOTE_INSPECTOR PRIVATE ${ENABLE_EXPERIMENTAL_FEATURES})

    # FIXME: Implement plugin process on Modern Hfcl. https://bugs.webkit.org/show_bug.cgi?id=185313
    HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_NETSCAPE_PLUGIN_API PRIVATE OFF)
else ()
    HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_LEGACY_ENCRYPTED_MEDIA PUBLIC ON)
    HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_INTL PUBLIC OFF)
    HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_PUBLIC_SUFFIX_LIST PRIVATE OFF)
    HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_WEBGL PUBLIC OFF)
    HFCL_OPTION_DEFAULT_PORT_VALUE(ENABLE_REMOTE_INSPECTOR PRIVATE OFF)
    HFCL_OPTION_DEFAULT_PORT_VALUE(USE_VERSION_STAMPER PRIVATE ON)
endif ()

HFCL_OPTION_END()

if (DEFINED ENV{HFCL_IGNORE_PATH})
    set(CMAKE_IGNORE_PATH $ENV{HFCL_IGNORE_PATH})
endif ()

if (NOT HFCL_LIBRARIES_DIR)
    if (DEFINED ENV{HFCL_LIBRARIES})
        file(TO_CMAKE_PATH "$ENV{HFCL_LIBRARIES}" HFCL_LIBRARIES_DIR)
    else ()
        file(TO_CMAKE_PATH "${CMAKE_SOURCE_DIR}/HfclLibraries/win" HFCL_LIBRARIES_DIR)
    endif ()
endif ()

set(CMAKE_PREFIX_PATH ${HFCL_LIBRARIES_DIR})

set(HFCL_LIBRARIES_INCLUDE_DIR "${HFCL_LIBRARIES_DIR}/include")
include_directories(${HFCL_LIBRARIES_INCLUDE_DIR})

if (${WTF_CPU_X86})
    set_property(GLOBAL PROPERTY FIND_LIBRARY_USE_LIB32_PATHS ON)
    set_property(GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS OFF)
    set(HFCL_LIBRARIES_LINK_DIR "${HFCL_LIBRARIES_DIR}/lib32")
    # FIXME: Remove ${HFCL_LIBRARIES_LINK_DIR} when find_library is used for everything
    link_directories("${CMAKE_BINARY_DIR}/lib32" "${HFCL_LIBRARIES_LINK_DIR}")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib32)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib32)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin32)
else ()
    set_property(GLOBAL PROPERTY FIND_LIBRARY_USE_LIB32_PATHS OFF)
    set_property(GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS ON)
    set(HFCL_LIBRARIES_LINK_DIR "${HFCL_LIBRARIES_DIR}/lib64")
    # FIXME: Remove ${HFCL_LIBRARIES_LINK_DIR} when find_library is used for everything
    link_directories("${CMAKE_BINARY_DIR}/lib64" "${HFCL_LIBRARIES_LINK_DIR}")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib64)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib64)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin64)
endif ()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

if (MSVC)
    include(OptionsMSVC)
endif ()

set(PORT Win)
set(JavaScriptCore_LIBRARY_TYPE SHARED)
set(WTF_LIBRARY_TYPE SHARED)
set(PAL_LIBRARY_TYPE STATIC)
set(HfclLegacy_LIBRARY_TYPE SHARED)

if (NOT ENABLE_UNIFIED_BUILDS AND WebCore_LIBRARY_TYPE MATCHES STATIC)
    set(WebCore_LIBRARY_TYPE OBJECT)
endif ()

find_package(ICU REQUIRED)

# If <winsock2.h> is not included before <windows.h> redefinition errors occur
# unless _WINSOCKAPI_ is defined before <windows.h> is included
add_definitions(-D_WINSOCKAPI_=)