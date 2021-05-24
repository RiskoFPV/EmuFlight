/*
 * This file is part of Cleanflight and Betaflight.
 *
 * Cleanflight and Betaflight are free software. You can redistribute
 * this software and/or modify this software under the terms of the
 * GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Cleanflight and Betaflight are distributed in the hope that they
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdbool.h>
#include <stdint.h>

#include "platform.h"

#ifdef USE_TARGET_CONFIG

#include "config_helper.h"

#include "io/serial.h"
#include "osd/osd.h"
#include "pg/pg.h"

#include "pg/pinio.h"
#include "pg/piniobox.h"


void targetConfiguration(void)
{
    osdConfigMutable()->core_temp_alarm = 85;

    // USER1: VTX PIT switch
    pinioConfigMutable()->config[0] = PINIO_CONFIG_MODE_OUT_PP | PINIO_CONFIG_OUT_INVERTED;
    pinioBoxConfigMutable()->permanentId[0] = 40;

    // USER2: Camera switch
    pinioConfigMutable()->config[1] = PINIO_CONFIG_MODE_OUT_PP;
    pinioBoxConfigMutable()->permanentId[1] = 41;
}
#endif
