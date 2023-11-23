package main

import "C"
import (
	"encoding/json"
	"fmt"
	"net/http"
	"os"
	"path/filepath"
)

//export RemoteServe
func RemoteServe(host *C.char, port int, unsafeDirectory *C.char) (int, *C.char) {
	directory := C.GoString(unsafeDirectory)
	if _, err := os.Stat(directory); err != nil {
		return 401, C.CString("Directory not exists")
	}
	mux := http.NewServeMux()
	mux.HandleFunc("/list", func(w http.ResponseWriter, r *http.Request) {
		files, err := filepath.Glob(filepath.Join(directory, "*.json"))
		if err != nil {
			w.WriteHeader(http.StatusInternalServerError)
			fmt.Fprintf(os.Stderr, "error: %v", err)
		}
		err = json.NewEncoder(w).Encode(files)
		if err != nil {
			w.WriteHeader(http.StatusInternalServerError)
			fmt.Fprintf(os.Stderr, "error: %v", err)
		}
	})
	if err := http.ListenAndServe(fmt.Sprintf("%s:%d", C.GoString(host), port), mux); err != nil {
		return 500, C.CString(err.Error())
	}
	return 0, C.CString("")
}

func main() {

}
