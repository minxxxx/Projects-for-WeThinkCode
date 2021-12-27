class CreateCuicuis < ActiveRecord::Migration
  def change
    create_table :cuicuis do |t|
      t.text :content
      t.integer :user_id
      t.datetime :created_at
      t.datetime :updated_at
    end
	add_reference :users, :cuicui, foreign_key: true
  end
end
