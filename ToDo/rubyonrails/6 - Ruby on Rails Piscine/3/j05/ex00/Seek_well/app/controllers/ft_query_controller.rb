
class FtQueryController < ApplicationController
  def index
    #
  end

  def create_db
    $db ||= SQLite3::Database.new('db/ft_sql')
    redirect_to action: :index
  end

  def create_table
    sql_text = 'CREATE TABLE IF NOT EXISTS clock_watch(
     ts_id  INTEGER AUTO_INCREMENT  ,
     month INTEGER ,
     year INTEGER,
     hour INTEGER,
     min INTEGER,
     sec INTEGER,
     race INTEGER,
     name VARCHAR(50),
     lap INTEGER
      );'
    $db.execute(sql_text) if $db
    sql_text = 'CREATE TABLE IF NOT EXISTS race(
     r_id INTEGER AUTO_INCREMENT,
     start VARCHAR(50)
     );'
    $db.execute(sql_text) if $db
    redirect_to action: :index
  end

  def drop_table
    sql_text = 'DROP TABLE IF EXISTS clock_watch ;'
    $db.execute(sql_text)
    sql_text = 'DROP TABLE IF EXISTS race ;'
    $db.execute(sql_text)
    redirect_to action: :index
  end

  def start_race
    #
  end

  def insert_time_stamp
    #
  end

  def delete_last
    #
  end

  def destroy_all
    #
  end

  def all_by_name
    #
  end

  def all_by_race
    #
  end

  def update_time_stamp
    #
  end
end
