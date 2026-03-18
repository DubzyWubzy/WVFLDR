set(TREMOLO_PLUGIN_NAME "WVFLDR")
juce_add_plugin(${PROJECT_NAME}
        VERSION
        0.0.1 # remember version semantics!
        COMPANY_NAME
        "DVBZY" # change this
        PLUGIN_MANUFACTURER_CODE
        Dvbz # change this
        PLUGIN_CODE
        Toot # change this
        FORMATS
        Standalone
        AU
        VST3
        IS_SYNTH
        FALSE
        NEEDS_MIDI_INPUT
        FALSE
        NEEDS_MIDI_OUTPUT
        FALSE
        VST3_AUTO_MANIFEST
        FALSE
        COPY_PLUGIN_AFTER_BUILD
        TRUE
        PRODUCT_NAME ${PROJECT_NAME}
)
       # The name of the final executable, which can differ from the target name


target_sources(${PROJECT_NAME}
    PRIVATE
        PluginEditor.cpp
        ../include/PluginEditor.h
        PluginProcessor.cpp
        ../include/PluginProcessor.h
        Parameters.cpp
        ../include/Parameters.h)


target_compile_definitions(${PROJECT_NAME}
    PUBLIC
        # JUCE_WEB_BROWSER and JUCE_USE_CURL would be on by default, but you might not need them.
        JUCE_WEB_BROWSER=0  # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_plugin` call
        JUCE_USE_CURL=0     # If you remove this, add `NEEDS_CURL TRUE` to the `juce_add_plugin` call
        JUCE_VST3_CAN_REPLACE_VST2=0)


target_link_libraries(${PROJECT_NAME}
    PRIVATE
        # AudioPluginData           # If we'd created a binary data target, we'd link to it here
        juce::juce_audio_utils
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)
