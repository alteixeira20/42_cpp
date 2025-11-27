#!/bin/bash

echo "===================="
echo "  BSP TEST SUITE"
echo "===================="

echo ""
echo "Triangle used:"
echo "A = (0,0)"
echo "B = (10,0)"
echo "C = (5,10)"
echo ""

echo "Test 1 — INSIDE (expected: true)"
./bsp 5 5
echo ""

echo "Test 2 — OUTSIDE (expected: false)"
./bsp 15 5
echo ""

echo "Test 3 — ON EDGE AB (expected: false)"
./bsp 5 0
echo ""

echo "Test 4 — ON EDGE BC (expected: false)"
./bsp 7.5 5
echo ""

echo "Test 5 — ON EDGE CA (expected: false)"
./bsp 2.5 5
echo ""

echo "Test 6 — VERTEX A (expected: false)"
./bsp 0 0
echo ""

echo "Test 7 — VERTEX B (expected: false)"
./bsp 10 0
echo ""

echo "Test 8 — VERTEX C (expected: false)"
./bsp 5 10
echo ""

echo "===================="
echo "     END OF TESTS"
echo "===================="
