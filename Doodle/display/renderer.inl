namespace doodle {

	template<class InIt>
	inline void Renderer::draw_points(InIt begin, InIt end) const noexcept
	{
		for (InIt i = begin; i != end; ++i)
			draw_point(*i);
	}

	template<class InIt>
	inline void Renderer::draw_lines(InIt begin, InIt end) const noexcept
	{
		for (InIt i = begin; i != end; ++i)
			draw_line(*i);
	}

	template<class InIt>
	inline void Renderer::draw_rects(InIt begin, InIt end) const noexcept
	{
		for (InIt i = begin; i != end; ++i)
			draw_rect(*i);
	}

	template<class InIt>
	inline void Renderer::draw_filled_rects(InIt begin, InIt end) const noexcept
	{
		for (InIt i = begin; i != end; ++i)
			draw_filled_rect(*i);
	}

}
