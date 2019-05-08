/* -LICENSE-START-
** Copyright (c) 2013 Blackmagic Design
**
** Permission is hereby granted, free of charge, to any person or organization
** obtaining a copy of the software and accompanying documentation covered by
** this license (the "Software") to use, reproduce, display, distribute,
** execute, and transmit the Software, and to prepare derivative works of the
** Software, and to permit third-parties to whom the Software is furnished to
** do so, all subject to the following:
**
** The copyright notices in the Software and this entire statement, including
** the above license grant, this restriction and the following disclaimer,
** must be included in all copies of the Software, in whole or in part, and
** all derivative works of the Software, unless such copies or derivative
** works are solely in the form of machine-executable object code generated by
** a source language processor.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
** SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
** FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
** ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
** -LICENSE-END-
*/

#ifndef BMD_CONFIG_H
#define BMD_CONFIG_H

#include "DeckLinkAPI.h"

class BMDConfig
{
public:
	BMDConfig();
	virtual ~BMDConfig();

	bool ParseArguments(int argc,  char** argv);
	void DisplayUsage(int status);
	void DisplayConfiguration();

	int						m_deckLinkIndex;
	int						m_displayModeIndex;

	int						m_audioChannels;
	int						m_audioSampleDepth;

	BMDVideoOutputFlags		m_outputFlags;
	BMDPixelFormat			m_pixelFormat;

	const char*				m_videoOutputFile;
	const char*				m_audioOutputFile;

private:
	char*					m_deckLinkName;
	char*					m_displayModeName;

	static const char* GetPixelFormatName(BMDPixelFormat pixelFormat);

	IDeckLink* GetDeckLink(int idx);
	IDeckLinkDisplayMode* GetDeckLinkDisplayMode(IDeckLink* deckLink, int idx);
};

#endif