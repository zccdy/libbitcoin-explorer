/**
 * Copyright (c) 2011-2014 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin_explorer.
 *
 * libbitcoin_explorer is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "precompile.hpp"
#include <explorer/commands/stealth-uncover-public.hpp>

#include <iostream>
#include <bitcoin/bitcoin.hpp>
#include <explorer/define.hpp>
#include <explorer/primitives/ec_public.hpp>

using namespace bc;
using namespace bc::explorer;
using namespace bc::explorer::commands;
using namespace bc::explorer::primitives;

console_result stealth_uncover_public::invoke(std::ostream& output,
    std::ostream& error)
{
    // Bound parameters.
    const auto& scan_secret = get_scan_secret_argument();
    const auto& spend_pubkey = get_spend_pubkey_argument();
    const auto& ephemeral_pubkey = get_ephemeral_pubkey_argument();

    auto scan_pubkey = uncover_stealth(ephemeral_pubkey, scan_secret,
        spend_pubkey);

    output << ec_public(scan_pubkey) << std::endl;
    return console_result::okay;
}