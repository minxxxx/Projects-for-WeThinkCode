
class FtQueryController < ApplicationController
  def index
    $time_stamps = []
    $all = []
    $db = SQLite3::Database.open('db/ft_sql') unless $db
    $time_stamps = $db.execute('select * from clock_watch') if $db
    $time_stamps << 'Database is empty or an other error occured' if $time_stamps.size.zero?
    $all << 'Not so fast, young padawan'
  rescue
    $time_stamps << 'Database is empty or an other error occured'
    $all << 'Not so fast, young padawan'
  end

  def create_db
    $db = SQLite3::Database.new('db/ft_sql')
    redirect_to action: :index
  end

  def create_table
    $db = SQLite3::Database.open('db/ft_sql') unless $db
    sql_text = 'CREATE TABLE IF NOT EXISTS clock_watch(
     ts_id  INTEGER PRIMARY KEY  ,
     day   INTEGER ,
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
     r_id INTEGER PRIMARY KEY,
     start VARCHAR(50)
     );'
    $db.execute(sql_text) if $db
    redirect_to action: :index
  end

  def drop_table
    $db = SQLite3::Database.open('db/ft_sql') unless $db
    sql_text = 'DROP TABLE IF EXISTS clock_watch ;'
    $db.execute(sql_text) if $db
    sql_text = 'DROP TABLE IF EXISTS race ;'
    $db.execute(sql_text)
    redirect_to action: :index
  end

  def start_race
    $db = SQLite3::Database.open('db/ft_sql') unless $db
    $runner_1 = params[:name_1].empty? ? 'anonymous' : params[:name_1]
    $runner_2 = params[:name_2].empty? ? 'anonymous' : params[:name_2]
    $runner_3 = params[:name_3].empty? ? 'anonymous' : params[:name_3]
    $runner_4 = params[:name_4].empty? ? 'anonymous' : params[:name_4]
    time = Time.now.getlocal
    sql_text = 'INSERT INTO race (start) VALUES (?) '
    sth = $db.prepare sql_text
    sth.execute time.to_s
    r_id = $db.execute('SELECT last_insert_rowid()')
    sql_text = 'INSERT INTO clock_watch (day, month, year, hour, min, sec, lap, race,name)
                VALUES ( ?,?,?,?,?,?,?,?,?) '
    sth = $db.prepare sql_text
    [$runner_1, $runner_2, $runner_3, $runner_4].each do |x|
      sth.execute(time.day, time.month, time.year, time.hour, time.min, time.sec, 1, r_id, x)
    end
    redirect_to action: :index
  end

  def insert_time_stamp
    time = Time.now.getlocal
    variables = params.present? && params.key?('params') ? params[:params] : params
    $db = SQLite3::Database.open('db/ft_sql') unless $db
    name1 = variables[:name_2] if variables[:name_2].present?
    name1 = variables[:name_3] if variables[:name_3].present?
    name1 = variables[:name_4] if variables[:name_4].present?
    name1 = variables[:name_1] if variables[:name_1].present?
    race = $db.execute('select max(r_id) from race')
    sql_text = 'select max(lap + 1) from clock_watch where name =  \'' + name1 + '\'
                and lap in (select max(lap) from clock_watch where name = \'' + name1 + '\')'
    lap = $db.execute sql_text
    sql_text = 'INSERT INTO clock_watch (day, month, year, hour, min, sec, lap, race, name)'
    sql_text += 'VALUES (?,?,?,?,?,?,?,?,?) '
    sth = $db.prepare sql_text
    sth.execute(time.day, time.month, time.year, time.hour, time.min, time.sec,
                lap, race[0][0].to_s, name1)
    redirect_to action: :index
  end

  def delete_last
    $db = SQLite3::Database.open('db/ft_sql') unless $db
    $db.execute('delete from clock_watch where ts_id in (select max(ts_id) from clock_watch)')
    redirect_to action: :index
  end

  def destroy_all
    $db = SQLite3::Database.open('db/ft_sql') unless $db
    $db.execute('delete from clock_watch')
    $db.execute('delete from race')
    redirect_to action: :index
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
