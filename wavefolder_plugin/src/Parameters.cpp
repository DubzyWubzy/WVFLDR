#include "../include/Parameters.h"

namespace
{
  auto& addParamToProcessor(juce::AudioProcessor& processor, auto parameter) {
    auto& parameterReference = *parameter;
    processor.addParameter(parameter.release());
    return parameterReference;
  }


  juce::AudioParameterFloat& createDriveParameter(juce::AudioProcessor& processor) {
    constexpr auto versionHint = 1;
    auto parameter = std::make_unique<juce::AudioParameterFloat>(
      juce::ParameterID{"drive", versionHint},
      "Drive",
      juce::NormalisableRange{1.0f, 6.0f, 0.01f, },
      2.0f, juce::AudioParameterFloatAttributes{});
    return addParamToProcessor(processor, std::move(parameter));
  }
}

Parameters::Parameters(juce::AudioProcessor& processor)
  : drive{createDriveParameter(processor)}
{
}
