#pragma once

namespace vp::component
{
	struct timestamp
	{
		date::year_month_day _value;
		std::uint8_t _hour;
	};
}