#ifndef BADGERSCONTROLLER2__VISIBILITY_CONTROL_H_
#define BADGERSCONTROLLER2__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define BADGERSCONTROLLER2_EXPORT __attribute__ ((dllexport))
    #define BADGERSCONTROLLER2_IMPORT __attribute__ ((dllimport))
  #else
    #define BADGERSCONTROLLER2_EXPORT __declspec(dllexport)
    #define BADGERSCONTROLLER2_IMPORT __declspec(dllimport)
  #endif
  #ifdef BADGERSCONTROLLER2_BUILDING_LIBRARY
    #define BADGERSCONTROLLER2_PUBLIC BADGERSCONTROLLER2_EXPORT
  #else
    #define BADGERSCONTROLLER2_PUBLIC BADGERSCONTROLLER2_IMPORT
  #endif
  #define BADGERSCONTROLLER2_PUBLIC_TYPE BADGERSCONTROLLER2_PUBLIC
  #define BADGERSCONTROLLER2_LOCAL
#else
  #define BADGERSCONTROLLER2_EXPORT __attribute__ ((visibility("default")))
  #define BADGERSCONTROLLER2_IMPORT
  #if __GNUC__ >= 4
    #define BADGERSCONTROLLER2_PUBLIC __attribute__ ((visibility("default")))
    #define BADGERSCONTROLLER2_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define BADGERSCONTROLLER2_PUBLIC
    #define BADGERSCONTROLLER2_LOCAL
  #endif
  #define BADGERSCONTROLLER2_PUBLIC_TYPE
#endif
#endif  // BADGERSCONTROLLER2__VISIBILITY_CONTROL_H_
// Generated 28-Nov-2023 19:05:28
// Copyright 2019-2020 The MathWorks, Inc.
