class FtQueryController < ApplicationController

	DATABASE_FILE_NAME = "ft_sql"

	def index

	end

	def create_db
		#
		#if file doesn't exists create empty db file
		if File.exist?(FtQueryController::DATABASE_FILE_NAME) == false
			FtQueryHelper::file_put_content(FtQueryController::DATABASE_FILE_NAME, "")
			SQLite3::Database.new(FtQueryController::DATABASE_FILE_NAME)
		end

		#
		#load sqlite3 file
		$db = SQLite3::Database.open(FtQueryController::DATABASE_FILE_NAME)
	end

	def create_table
		self.create_db

		#
		#ADD clock_watch TABLE
		rows = $db.execute <<-SQL
        	create table if not exists clock_watch(
				ts_id INTEGER PRIMARY KEY AUTOINCREMENT,
				day INTEGER,
				month INTEGER,
				year INTEGER,
				hour INTEGER,
				min INTEGER,
				sec INTEGER,
				race INTEGER,
				name VARCHAR(50),
				lap INTEGER
			);
			SQL
		#
		#ADD race TABLE
		rows = $db.execute <<-SQL
        	create table if not exists race(
				r_id INTEGER PRIMARY KEY AUTOINCREMENT,
				start VARCHAR(50)
			);
			SQL
	end

	def drop_table
		self.create_db

		#
		#DROP clock_watch TABLE
		$db.execute <<-SQL
        	drop table if exists clock_watch
			SQL
		#
		#DROP race TABLE
		$db.execute <<-SQL
        	drop table if exists race
			SQL
	end

	def start_race

	end

	def insert_time_stamp

	end

	def delete_last

	end

	def destroy_all

	end

	def all_by_name

	end

	def all_by_race

	end

	def update_time_stamp

	end

	private
end
