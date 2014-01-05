/*
 * cofmsg_stats.h
 *
 *  Created on: 18.03.2013
 *      Author: andi
 */

#ifndef COFMSG_STATS_H_
#define COFMSG_STATS_H_ 1

#include "cofmsg.h"

namespace rofl
{

/**
 *
 */
class cofmsg_stats :
	public cofmsg
{
private:

	cmemory				body;	// for experimental statistics messages

	union {
		uint8_t*						ofhu_stats_request;
		struct openflow10::ofp_stats_request*		ofhu10_stats_request;
		struct openflow12::ofp_stats_request*		ofhu12_stats_request;
		struct openflow13::ofp_multipart_request*	ofhu13_multipart_request;
	} ofhu;

#define ofh_stats_request   			ofhu.ofhu_stats_request
#define ofh10_stats_request 			ofhu.ofhu10_stats_request
#define ofh12_stats_request 			ofhu.ofhu12_stats_request
#define ofh13_multipart_request 		ofhu.ofhu13_multipart_request

public:


	/** constructor
	 *
	 */
	cofmsg_stats(
			uint8_t of_version = 0,
			uint32_t xid = 0,
			uint32_t stats_type = 0,
			uint32_t stats_flags = 0,
			uint8_t *data = (uint8_t*)0,
			size_t datalen = 0);


	/**
	 *
	 */
	cofmsg_stats(
			cofmsg_stats const& stats);


	/**
	 *
	 */
	cofmsg_stats&
	operator= (
			cofmsg_stats const& stats);


	/** destructor
	 *
	 */
	virtual
	~cofmsg_stats();


	/**
	 *
	 */
	cofmsg_stats(cmemory *memarea);


	/** reset packet content
	 *
	 */
	virtual void
	reset();


	/**
	 *
	 */
	virtual void
	resize(size_t len);


	/** returns length of packet in packed state
	 *
	 */
	virtual size_t
	length() const;


	/**
	 *
	 */
	virtual void
	pack(uint8_t *buf = (uint8_t*)0, size_t buflen = 0);


	/**
	 *
	 */
	virtual void
	unpack(uint8_t *buf, size_t buflen);


	/** parse packet and validate it
	 */
	virtual void
	validate();


public:


	/**
	 *
	 */
	uint16_t
	get_stats_type() const;

	/**
	 *
	 */
	void
	set_stats_type(uint16_t type);

	/**
	 *
	 */
	uint16_t
	get_stats_flags() const;

	/**
	 *
	 */
	void
	set_stats_flags(uint16_t flags);

	/**
	 *
	 */
	cmemory&
	get_body();

public:

	friend std::ostream&
	operator<< (std::ostream& os, cofmsg_stats const& msg) {
		std::string s_flags;
		switch (msg.get_version()) {
		case openflow10::OFP_VERSION: {
			if (msg.get_stats_flags() & openflow10::OFPSF_REPLY_MORE)
				s_flags.append("MORE ");
		} break;
		case openflow12::OFP_VERSION: {
			if (msg.get_stats_flags() & openflow12::OFPSF_REPLY_MORE)
				s_flags.append("MORE ");
		} break;
		default: {
			s_flags.append("unsupported OF version");
		} break;
		}
		os << dynamic_cast<cofmsg const&>( msg );
		os << indent(2) << "<cofmsg_stats ";
		os << "type:" << (int)msg.get_stats_type() << " ";
		os << "flags:" << s_flags << " ";
		os << ">" << std::endl;;
		return os;
	};
};


typedef cofmsg_stats cofmsg_stats_request;
typedef cofmsg_stats cofmsg_stats_reply;
typedef cofmsg_stats cofmsg_multipart_request;
typedef cofmsg_stats cofmsg_multipart_reply;


} // end of namespace rofl

#endif /* COFMSG_STATS_H_ */
