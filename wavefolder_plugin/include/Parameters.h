#pragma once
#include <juce_core/juce_core.h>
#include <juce_audio_processors/juce_audio_processors.h>
struct Parameters {
    explicit Parameters(juce::AudioProcessor&);

    juce::AudioParameterFloat& drive;

    JUCE_DECLARE_NON_COPYABLE(Parameters)
    JUCE_DECLARE_NON_MOVEABLE(Parameters)

};

