#ifndef H_XD_GRAPHICS_STOCK_TEXT_FORMATTER
#define H_XD_GRAPHICS_STOCK_TEXT_FORMATTER

#include <glm/glm.hpp>
#include <string>
#include <ctime>
#include <boost/unordered_map.hpp>
#include <xd/graphics/text_formatter.h>

namespace xd
{
	class stock_text_formatter : public text_formatter
	{
	public:
		stock_text_formatter();
		virtual ~stock_text_formatter();

		bool has_color(const std::string& name);
		glm::vec4 get_color(const std::string& name);
		void set_color(const std::string& name, const glm::vec4& color);

		void reset_typewriter(int timer = 0);

	private:
		typedef boost::unordered_map<std::string, glm::vec4> color_map_t;
		typedef boost::unordered_map<int, std::clock_t> typewriter_timer_map_t;

		void type_decorator(text_decorator& decorator, const formatted_text& text, const text_decorator_args& args);
		void bold_decorator(text_decorator& decorator, const formatted_text& text, const text_decorator_args& args);
		void italic_decorator(text_decorator& decorator, const formatted_text& text, const text_decorator_args& args);
		void color_decorator(text_decorator& decorator, const formatted_text& text, const text_decorator_args& args);
		void shadow_decorator(text_decorator& decorator, const formatted_text& text, const text_decorator_args& args);
		void outline_decorator(text_decorator& decorator, const formatted_text& text, const text_decorator_args& args);
		void spacing_decorator(text_decorator& decorator, const formatted_text& text, const text_decorator_args& args);
		void rainbow_decorator(text_decorator& decorator, const formatted_text& text, const text_decorator_args& args);
		void typewriter_decorator(text_decorator& decorator, const formatted_text& text, const text_decorator_args& args);

		color_map_t m_colors;
		typewriter_timer_map_t m_typewriter_timers;
	};
}

#endif
