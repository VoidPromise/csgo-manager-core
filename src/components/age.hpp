#pragma once

namespace vp::component
{
	struct age
	{
		std::uint8_t _value;
		date::year_month_day _birth;
		date::year_month_day _death;
	};
}