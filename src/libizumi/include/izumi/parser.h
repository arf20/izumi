/*
 * This file is part of Izumi.
 *
 * Izumi is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * Izumi is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * Izumi. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef PARSER_H
#define PARSER_H

#include <izumi/data_structs.h>

/**
 * @file parser.h
 *
 * Dump parsing functions.
 */

/**
 * @param cycle The current cycle count.
 * @param line The input line.
 *
 * Increment the cycle count based on the input line.
 */
void cycle_increment(uint64_t *cycle, char *line);

/**
 * @param tables_array The array of tables.
 * @param line The input line.
 *
 * Add an instruction to the tables array.
 */
void new_instruction(InstructionTableArray *tables_array, char *line);

/**
 * @param tables_array The array of tables.
 * @param line The input line.
 *
 * Set the data of the instruction in the tables array.
 */
void line_of_data(InstructionTableArray *tables_array, char *line);

/**
 * @param tables_array The array of tables.
 * @param cycle The current cycle count.
 * @param line The input line.
 *
 * Add a new stage to the instruction in the tables array.
 */
void new_stage(InstructionTableArray *tables_array, uint64_t cycle, char *line);

/**
 * @param tables_array The array of tables.
 * @param cycle The current cycle count.
 * @param line The input line.
 *
 * End the stage of the instruction in the tables array.
 */
void end_stage(InstructionTableArray *tables_array, uint64_t cycle, char *line);

/**
 * @param tables_array The array of tables.
 * @param cycle The current cycle count.
 * @param line The input line.
 *
 * Retire the instruction in the tables array.
 */
void retire_instruction(InstructionTableArray *tables_array, uint64_t cycle, char *line);

/**
 * @param file_name The name of the file.
 * @return An InstructionTableArray with the parsed data.
 *
 * Parse the file and fill an InstructionTableArray with the data.
 */
InstructionTableArray parse_file(const char *file_name);

#endif

