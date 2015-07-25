/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "rofl/common/openflow/messages/cofmsg.h"

using namespace rofl::openflow;

size_t
cofmsg::length() const
{
	return sizeof(struct rofl::openflow::ofp_header);
}



void
cofmsg::pack(
		uint8_t *buf, size_t buflen)
{
	len = length(); // call overwritten length() method here

	if ((0 == buf) || (0 == buflen))
		return;

	if (buflen < cofmsg::length())
		throw eMsgInval("cofmsg::pack() buf too short");

	struct rofl::openflow::ofp_header* hdr =
			(struct rofl::openflow::ofp_header*)buf;

	hdr->version = version;
	hdr->type    = type;
	hdr->length  = htobe16(len);
	hdr->xid     = htobe32(xid);
}



void
cofmsg::unpack(
		uint8_t *buf, size_t buflen)
{
	if ((0 == buf) || (0 == buflen))
		return;

	if (buflen < cofmsg::length())
		throw eBadSyntaxTooShort("cofmsg::unpack() buf too short");

	struct rofl::openflow::ofp_header* hdr =
			(struct rofl::openflow::ofp_header*)buf;

	version = hdr->version;
	type    = hdr->type;
	len     = be16toh(hdr->length);
	xid     = be32toh(hdr->xid);

	if ((len < cofmsg::length()) || (len > buflen))
		throw eMsgInval("cofmsg::unpack() buf too short (payload)");
}


