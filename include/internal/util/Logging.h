/*
 * Copyright (C) 2003, 2006, 2013 Apple Computer, Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef Logging_h
#define Logging_h

#include "WTF\Assertions.h"
#include <string>

#if !LOG_DISABLED

#ifndef LOG_CHANNEL_PREFIX
#define LOG_CHANNEL_PREFIX Log
#endif

namespace WebCore {

#define WEBCORE_LOG_CHANNELS(M) \
M(Animations) \
M(Archives) \
M(BackForward) \
M(Compositing) \
M(DiskImageCache) \
M(Editing) \
M(Events) \
M(FTP) \
M(FileAPI) \
M(Frames) \
M(Gamepad) \
M(History) \
M(IconDatabase) \
M(LiveConnect) \
M(Loading) \
M(Media) \
M(Network) \
M(NotYetImplemented) \
M(PageCache) \
M(PlatformLeaks) \
M(Plugins) \
M(PopupBlocking) \
M(Progress) \
M(ResourceLoading) \
M(SQLDatabase) \
M(SpellingAndGrammar) \
M(StorageAPI) \
M(Threading) \
M(WebAudio) \
M(WebGL) \

#define DECLARE_LOG_CHANNEL(name) \
extern WTFLogChannel JOIN_LOG_CHANNEL_WITH_PREFIX(LOG_CHANNEL_PREFIX, name);

    WEBCORE_LOG_CHANNELS(DECLARE_LOG_CHANNEL)

#undef DECLARE_LOG_CHANNEL

    extern WTFLogChannel* logChannels[];
    extern size_t logChannelCount;

    std::string logLevelString();
    WTFLogChannel* logChannelByName(const std::string&);
    void initializeLoggingChannelsIfNecessary();
}

#endif // !LOG_DISABLED

#endif // Logging_h
