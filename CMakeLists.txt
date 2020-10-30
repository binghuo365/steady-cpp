cmake_minimum_required(VERSION 3.5)
project(steady)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

if(NOT MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
    add_definitions(-D_WIN32_WINNT=0x600)
endif()
add_definitions(-D_WIN32_WINNT=0x600)

find_package(Threads REQUIRED)

MESSAGE(STATUS "This is BINARY dir " ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir " ${PROJECT_SOURCE_DIR})
MESSAGE(STATUS "This is CMAKE_MODULE_PATH " ${CMAKE_MODULE_PATH})

add_subdirectory(third_party/grpc ${CMAKE_CURRENT_BINARY_DIR}/grpc EXCLUDE_FROM_ALL)
message(STATUS "Using gRPC via add_subdirectory.")
#set(_PROTOBUF_LIBPROTOBUF libprotobuf)
#set(_REFLECTION grpc++_reflection)

#if(CMAKE_CROSSCOMPILING)
#    find_program(_PROTOBUF_PROTOC protoc)
#else()
#    set(_PROTOBUF_PROTOC $<TARGET_FILE:protobuf::protoc>)
#endif()

#set(_GRPC_GRPCPP grpc++)

#if(CMAKE_CROSSCOMPILING)
#    find_program(_GRPC_CPP_PLUGIN_EXECUTABLE grpc_cpp_plugin)
#else()
#    set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:grpc_cpp_plugin>)
#endif()

include_directories(./include)
link_directories(./cmake-build-debug/
        ./cmake-build-debug/grpc
        ./cmake-build-debug/grpc/third_party/cares/cares/lib
        ./cmake-build-debug/grpc/third_party/zlib
        ./cmake-build-debug/grpc/third_party/protobuf
        ./cmake-build-debug/grpc/third_party/re2
        ./cmake-build-debug/grpc/third_party/abseil-cpp/absl/base
        ./cmake-build-debug/grpc/third_party/abseil-cpp/absl/algorithm
        ./cmake-build-debug/grpc/third_party/abseil-cpp/absl/container
        ./cmake-build-debug/grpc/third_party/abseil-cpp/absl/flags
        ./cmake-build-debug/grpc/third_party/abseil-cpp/absl/functional
        ./cmake-build-debug/grpc/third_party/abseil-cpp/absl/hash
        ./cmake-build-debug/grpc/third_party/abseil-cpp/absl/memory
        ./cmake-build-debug/grpc/third_party/abseil-cpp/absl/numeric
        ./cmake-build-debug/grpc/third_party/abseil-cpp/absl/random
        ./cmake-build-debug/grpc/third_party/abseil-cpp/absl/strings
        ./cmake-build-debug/grpc/third_party/abseil-cpp/absl/time
        ./cmake-build-debug/grpc/third_party/abseil-cpp/absl/synchronization
        ./cmake-build-debug/grpc/third_party/abseil-cpp/absl/utility
        ./cmake-build-debug/grpc/third_party/abseil-cpp/absl/types)


#include_directories("${PROJECT_INCLUDE_DIR}")
#include_directories("${PROJECT_SOURCE_DIR}")


add_subdirectory(examples)

aux_source_directory(./src SRC_LIST)
add_library(${PROJECT_NAME} STATIC ${SRC_LIST})

# jsoncpp
find_package(Jsoncpp REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC
        Jsoncpp_lib
        address_sorting
        gpr
        grpc
        grpc++
        cares
        crypto
        ssl
        zlibstatic
        grpc++_reflection
        grpc++_unsecure
        grpc_unsecure
        grpcpp_channelz
        grpc++_error_details
        grpc++_alts
        upb
        libprotobuf
        libprotobuf-lite
        Ws2_32
        absl_base
        absl_dynamic_annotations
        absl_exponential_biased
        absl_log_severity
        absl_malloc_internal
        absl_periodic_sampler
        absl_raw_logging_internal
        absl_scoped_set_env
        absl_spinlock_wait
        absl_throw_delegate
        absl_strings
        absl_strings_internal
        absl_str_format_internal
        absl_cord
        absl_flags
        absl_flags_config
        absl_flags_internal
        absl_flags_marshalling
        absl_flags_program_name
        absl_flags_parse
        absl_flags_usage
        absl_flags_usage_internal
        absl_hash
        absl_int128
        absl_random_distributions
        absl_random_internal_distribution_test_util
        absl_random_internal_pool_urbg
        absl_random_internal_randen
        absl_random_internal_randen_hwaes
        absl_random_internal_randen_hwaes_impl
        absl_random_internal_randen_slow
        absl_random_internal_seed_material
        absl_random_seed_gen_exception
        absl_random_seed_sequences
        absl_graphcycles_internal
        absl_synchronization
        absl_civil_time
        absl_time
        absl_time_zone
        absl_bad_any_cast_impl
        absl_bad_optional_access
        absl_bad_variant_access
        re2)