require 'test_helper'

POPULATE = "post 'create_db'
            post 'create_table'
            post 'start_race', { name_1: 'foo',
                                      name_2: 'bar',
                                      name_3: 'baz',
                                      name_4: '42'  }".freeze
BG_POPULATE= "post 'create_db'
             post 'drop_table'
             post 'create_table'
             post 'start_race', { name_1: 'foo',
                                       name_2: 'bar',
                                       name_3: 'baz',
                                       name_4: '42'  }
            post 'insert_time_stamp', params: { name_1: 'foo' }
            post 'insert_time_stamp', params: { name_2: 'bar' }
            post 'insert_time_stamp', params: { name_3: 'baz' }
            post 'insert_time_stamp', params: { name_1: 'foo' }
            post 'insert_time_stamp', params: { name_2: 'bar' }
            post 'insert_time_stamp', params: { name_3: 'baz' }
            post 'insert_time_stamp', params: { name_1: 'foo' }
            post 'insert_time_stamp', params: { name_2: 'bar' }
            post 'insert_time_stamp', params: { name_3: 'baz' }
            post 'start_race', params: { name_1: 'foo',
                                        name_2: 'bar',
                                        name_3: 'baz',
                                        name_4: '42' }
            post 'insert_time_stamp', params: { name_1: 'foo' }
            post 'insert_time_stamp', params: { name_2: 'bar' }
            post 'insert_time_stamp', params: { name_3: 'baz' }
            post 'insert_time_stamp', params: { name_1: 'foo' }
            post 'insert_time_stamp', params: { name_2: 'bar' }
            post 'insert_time_stamp', params: { name_3: 'baz' }
            post 'insert_time_stamp', params: { name_1: 'foo' }
            post 'insert_time_stamp', params: { name_2: 'bar' }
            post 'insert_time_stamp', params: { name_3: 'baz' }".freeze

class FtQueryControllerTest < ActionController::TestCase
  test 'db_file_creation' do
    post 'create_db'
    assert_equal($db.class, SQLite3::Database)
  end
    test 'db_table_creation' do
    post 'create_db'
    post 'create_table'
    query_clock = $db.execute("SELECT * FROM 'sqlite_master' ")[0][1]
    query_race = $db.execute("SELECT * FROM 'sqlite_master' ")[1][1]
    assert_equal(query_clock, 'clock_watch')
    assert_equal(query_race, 'race')
  end
  test 'db_drop' do
    post 'create_db'
    post 'create_table'
    post 'drop_table'
    assert($time_stamps = ['table has been droped'])
    assert($all = ['table has been droped'])
  end
  test 'start_race' do
    eval(POPULATE)
    query_race = $db.execute('SELECT * FROM race')
    assert_equal(query_race.first[0], 1)
    assert_kind_of(Time, Time.parse(query_race[0][1]))

    query_time = $db.execute('SELECT * FROM clock_watch')

    assert_equal(query_time.count, 4)
    assert_equal(query_time[0][8], 'foo')
    assert_equal(query_time[1][8], 'bar')
    assert_equal(query_time[2][8], 'baz')
    assert_equal(query_time[3][8], '42')
    assert_equal(query_time[0][9], 1)
    assert_equal(query_time[0][0] + 1, query_time[1][0])
    assert_equal(query_time[0][7], query_race[0][0])
  end
  test 'insert_time_stamp' do
    eval(POPULATE)
    post 'insert_time_stamp', params: { name_1: 'foo' }
    post 'insert_time_stamp', params: { name_1: 'foo' }
    query_time = $db.execute('SELECT * FROM clock_watch')
    last = query_time.count - 1
    lap = query_time[last].last
    lap_b4 = query_time[last - 1].last
    assert(lap_b4 + 1 == lap)
    assert(query_time[last][8] == 'foo')
    assert(query_time[last - 1][8] == 'foo')
    assert_equal(query_time[last][7], query_time[last - 1][7])
  end
  test 'delete_last' do
    eval(POPULATE)
    query_time1 = $db.execute('SELECT * FROM clock_watch').last
    post 'delete_last'
    query_time2 = $db.execute('SELECT * FROM clock_watch').last
    refute_equal(query_time2, query_time1)
    refute(query_time2.is_a?(String))
    refute(query_time1.is_a?(String))
  end
  test 'destroy_all' do
    eval(POPULATE)
    post 'destroy_all'
    time = $db.execute('SELECT * FROM clock_watch')
    race = $db.execute('SELECT * FROM race')
    assert_equal(race.count, 0)
    assert_equal(time.count, 0)
  end
  test 'update time stamp' do
    eval(BG_POPULATE)
    post 'update_time_stamp', params: { name_1: 'new_foo' }
    updated = $db.execute("SELECT * FROM clock_watch WHERE name='new_foo'")
    assert_equal(updated.count, 4)
    assert_equal(updated.map { |x| x[7] }.uniq!.to_s, '[1]')
  end
  test "all_by"do
    eval(BG_POPULATE)
    post "all_by_name"
    assert_equal($all[0][0], '42')
    assert_equal($all[1][0], '42')
    assert_equal($all[2][0], 'bar')
    assert_equal($all[10][0], 'baz')
    assert_equal($all[20][0],'foo')
    post "all_by_race"
    first_race = $all.each.map{|x| x[5]}.take(12).uniq
    assert_equal(first_race, [0])
    second_race = $all.each.map{|x| x[5]}.drop(13).uniq
    assert_equal(second_race, [1])
  end
end
