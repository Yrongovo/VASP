/*
 * MIT License
 *
 * Copyright (c) 2022 Qualcomm Innovation Center, Inc., SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Project: V2X Application Spoofing Platform (VASP)
 * Author: Raashid Ansari
 * Email: quic_ransari@quicinc.com
 */

#include <omnetpp/csimulation.h>
#include <omnetpp/distrib.h>
#include <vasp/attack/speed/RandomOffset.h>
#include <vasp/messages/BasicSafetyMessage_m.h>

namespace vasp {
namespace attack {
namespace speed {
RandomOffset::RandomOffset(double const offset)
    : offset_(offset)
{
}

void RandomOffset::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("RandomSpeedOffset");

    auto rng = getEnvir()->getRNG(0);
    bsm->setSenderSpeed(bsm->getSenderSpeed() + veins::Coord(uniform(rng, -offset_, offset_), uniform(rng, -offset_, offset_)));
}
} // namespace speed
} // namespace attack
} // namespace vasp