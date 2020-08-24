package imgui

// #include "wrapper/Utils.h"
import "C"

// Spinner draw a rotating spinner
func Spinner(label string, radius float32, thickness int) {
	labelArg, labelFin := wrapString(label)
	defer labelFin()
	C.iggSpinner(labelArg, C.float(radius), C.int(thickness))
}
