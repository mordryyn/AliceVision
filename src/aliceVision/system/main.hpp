// This file is part of the AliceVision project.
// Copyright (c) 2020 AliceVision contributors.
// This Source Code Form is subject to the terms of the Mozilla Public License,
// v. 2.0. If a copy of the MPL was not distributed with this file,
// You can obtain one at https://mozilla.org/MPL/2.0/.

#pragma once

/**
 * @file \c main() function wrapper
 * Provides an implementation of \c main() that automatically catches and logs
 * otherwise unhandled exception.
 *
 * To use you need to change your source file containing \c main() as such:
 * 1. Include this header
 * 2. Rename \c main() to \c aliceVision_main()
 */

#include "Logger.hpp"

#include <stdexcept>

/**
 * @brief Name of the application entry function, replacing \c main().
 */
int aliceVision_main(int argc, char* argv[]);

// Inline to ensure the right main() is used (libf2c also has one...)
int main(int argc, char* argv[])
{
    try
    {
        return aliceVision_main(argc, argv);
    }
    catch(const std::exception& e)
    {
        ALICEVISION_LOG_FATAL(e.what());
    }
    catch(...)
    {
        ALICEVISION_LOG_FATAL("Unknown exception");
    }
    return EXIT_FAILURE;
}
