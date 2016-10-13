/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (600, 120);
    
    label.setJustificationType (Justification::centred);
    addAndMakeVisible (label);
    
    for (int i = 0; i < 7; ++i)
    {
        addAndMakeVisible (buttons.add (new TextButton (String (i + 1))));
        buttons[i]->addListener (this);
    }
    
    resized();
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colours::grey);
}

void MainContentComponent::resized()
{
    Rectangle<int> r (getLocalBounds());
    
    label.setBounds (r.removeFromBottom (r.getHeight() / 2).reduced (5));
    
    if (buttons.size() > 0)
    {
        const int width = r.getWidth() / buttons.size();
        
        for (int i = 0; i < buttons.size(); ++i)
        {
            buttons[i]->setBounds (r.removeFromLeft (width).reduced(5));
        }
    }
}

void MainContentComponent::buttonClicked (Button* b)
{
    if (buttons.contains (b))
    {
        label.setText (String (buttons.indexOf (b) + 1), dontSendNotification);
    }
}
