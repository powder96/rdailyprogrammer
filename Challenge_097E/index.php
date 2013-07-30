<?php
	/**
	 * Solution for the /r/dailyprogrammer/ challenge #097E (http://reddit.com/zkdv1/)
	 * Copyright (C) 2013 powder96 <https://github.com/powder96/>
	 *
	 * This program is free software: you can redistribute it and/or modify
	 * it under the terms of the GNU General Public License as published by
	 * the Free Software Foundation, either version 3 of the License, or
	 * (at your option) any later version.
	 *
	 * This program is distributed in the hope that it will be useful,
	 * but WITHOUT ANY WARRANTY; without even the implied warranty of
	 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	 * GNU General Public License for more details.
	 *
	 * You should have received a copy of the GNU General Public License
	 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
	 */

	echo '<pre>' . htmlspecialchars(printTextFilesContents(__DIR__, isset($_GET['r']))) .
	     '</pre>';
	
	function printTextFilesContents($filename, $processSubdirectories = false) {
		$output = '';
		if(is_dir($filename)) {
			$output .= "\n===\n" .
				'=== ' . $filename . "\n" .
				"===\n";
			$files = scandir($filename);
			foreach($files as $file)
				if($file != '.' && $file != '..') {
					$nextFilename = $filename . '/' . $file;
					if((is_dir($nextFilename) && $processSubdirectories) ||
					   is_file($nextFilename))
						$output .= printTextFilesContents($nextFilename);
				}
		}
		else
			if(pathinfo($filename, PATHINFO_EXTENSION) === 'txt') {
				$output .= "\n" .
					'=== ' . basename($filename) . ' (' . filesize($filename) . " bytes)\n" .
					file_get_contents($filename) .
					"\n";
			}
		return $output;
	}