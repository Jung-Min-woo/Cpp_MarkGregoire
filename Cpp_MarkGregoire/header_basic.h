#pragma once
#if __has_include(<optional>)
    #include <optional>
#elif __has_include(<experimental/optional)
    #include<experimental/optional>
#endif

#include <string_view>
class Preferences;

class Logger{
    public:
        static void setPreferences(const Preference& prefs);
        static void logError(std::string_view error);
}