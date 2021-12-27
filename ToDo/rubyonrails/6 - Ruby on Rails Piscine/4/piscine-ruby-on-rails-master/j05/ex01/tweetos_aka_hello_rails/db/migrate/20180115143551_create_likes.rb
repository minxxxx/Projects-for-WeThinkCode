class CreateLikes < ActiveRecord::Migration
  def change
    create_table :likes do |t|
      t.integer :user_id
	  t.integer :cuicui_id
      t.datetime :created_at
      t.datetime :updated_at
    end
	add_reference :likes, :cuicui, foreign_key: true
	add_reference :likes, :user, foreign_key: true
  end
end
