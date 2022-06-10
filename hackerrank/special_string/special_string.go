package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

// Complete the substrCount function below.
func substrCount(n int32, s string) int64 {
    var p1, p2, res, save1, save2, isSpecial int = 0, 0, 0, 0, 0, 1

    for p2 < len(s) {
        isSpecial = 1
        if(p1 == p2) {
            p2++
            continue
        }

        if(s[p1] == s[p2]) {
            if (p2 == len(s) - 1) {
                res += (((p2 - p1 + 1) * (p2 - p1)) / 2)
                return int64(res) + int64(len(s))
            }
            p2++
            continue
        }
        res += (((p2 - p1) * (p2 - p1 - 1)) / 2)

        save1 = p2 - p1
        save2 = p2
        for i := 0 ; i < save1 ; i++ {
            p2++
            if (p2 >= len(s)) {
                res += p2 - save2 - 1 
                return int64(res) + int64(len(s))
            }

            if (s[p1] != s[p2]) {
                isSpecial = 0
                break
            }
        }
        if (isSpecial == 1){
            res += p2 - save2
        } else {
            res += p2 - save2 - 1
        }
        p1, p2 = save2, save2 
    }

    return int64(res) + int64(len(s))
}

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

    nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    n := int32(nTemp)

    s := readLine(reader)

    result := substrCount(n, s)

    fmt.Println(result)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
    if err != nil {
        panic(err)
    }
}
