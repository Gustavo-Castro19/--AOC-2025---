package main

import (
	"bufio"
	"fmt"
	"log"
	"math/big"
	"os"
)

func findMaxJoltage12(line string) (*big.Int, error) {
	const neededDigits = 12
	if len(line) < neededDigits {
		return nil, fmt.Errorf("line must contain at least %d digits, got %d", neededDigits, len(line))
	}

	removeCount := len(line) - neededDigits
	if removeCount < 0 {
		return nil, fmt.Errorf("not enough digits")
	}

	stack := make([]byte, 0, neededDigits)
	removalsLeft := removeCount

	for i := 0; i < len(line); i++ {
		currentDigit := line[i]
		
		for len(stack) > 0 && removalsLeft > 0 && currentDigit > stack[len(stack)-1] {
			stack = stack[:len(stack)-1]
			removalsLeft--
		}
		
		stack = append(stack, currentDigit)
	}

	if removalsLeft > 0 {
		stack = stack[:len(stack)-removalsLeft]
	}

	if len(stack) > neededDigits {
		stack = stack[:neededDigits]
	}

	result := new(big.Int)
	resultStr := string(stack)
	
	result, success := result.SetString(resultStr, 10)
	if !success {
		return nil, fmt.Errorf("failed to parse result as number: %s", resultStr)
	}

	return result, nil
}

func main() {
	fd, err := os.Open("input.txt")
	if err != nil {
		log.Fatal(err)
	}
	defer fd.Close()

	scanner := bufio.NewScanner(fd)
	totalJoltage := new(big.Int)
	lineCount := 0
	
	for scanner.Scan() {
		line := scanner.Text()
		lineCount++
		
		maxJoltage, err := findMaxJoltage12(line)
		if err != nil {
			log.Printf("Error processing line %d '%s': %v", lineCount, line, err)
			continue
		}
		
		totalJoltage.Add(totalJoltage, maxJoltage)
	}

	if err := scanner.Err(); err != nil {
		log.Fatal(err)
	}

	fmt.Printf("\nTotal joltage: %s\n", totalJoltage.String())
}
