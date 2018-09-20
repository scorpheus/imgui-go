package imgui

const (
	//SelecTableFlagsDontClosePopups Clicking this don't close parent popup window
	SelecTableFlagsDontClosePopups = 1 << iota
	// SelecTableFlagsSpanAllColumns Selectable frame can span all columns (text will still fit in current column)
	SelecTableFlagsSpanAllColumns
	// SelecTableFlagsAllowDoubleClick Generate press events on double clicks too
	SelecTableFlagsAllowDoubleClick
)
