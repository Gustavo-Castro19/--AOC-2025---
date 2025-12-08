package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
)

func findMaxJoltage(line string) (int, error) {
	if len(line) < 2 {
		return 0, fmt.Errorf("line must contain at least 2 digits")
	}

	maxJoltage := 0

	runes := []rune(line)

	for i := 0; i < len(runes); i++ {
		digit1, err1 := strconv.Atoi(string(runes[i]))
		if err1 != nil {
			return 0, fmt.Errorf("invalid digit '%c' at position %d", runes[i], i)
		}

		for j := i + 1; j < len(runes); j++ {
			digit2, err2 := strconv.Atoi(string(runes[j]))
			if err2 != nil {
				return 0, fmt.Errorf("invalid digit '%c' at position %d", runes[j], j)
			}

			joltage := digit1*10 + digit2
			
			if joltage > maxJoltage {
				maxJoltage = joltage
			}
		}
	}

	return maxJoltage, nil
}

func main() {
	fd, err := os.Open("input.txt")

	if err != nil {
		log.Fatal(err)
	}
	defer fd.Close()

	scanner := bufio.NewScanner(fd)
	totalJoltage := 0
	lineCount := 0
	
	for scanner.Scan() {
		line := scanner.Text()
		lineCount++
		
		maxJoltage, err := findMaxJoltage(line)
		if err != nil {
			log.Printf("Error processing line %d '%s': %v", lineCount, line, err)
			continue
		}
		
		totalJoltage += maxJoltage
	}

	if err := scanner.Err(); err != nil {
		log.Fatal(err)
	}

	fmt.Printf("\nTotal joltage: %d\n", totalJoltage)
}
