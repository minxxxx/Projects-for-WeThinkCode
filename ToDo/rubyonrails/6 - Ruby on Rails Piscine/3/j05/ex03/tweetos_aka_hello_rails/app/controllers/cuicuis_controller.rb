class CuicuisController < ApplicationController
  before_action :set_cuicui, only: [:show, :edit, :update, :destroy]

  # GET /cuicuis
  # GET /cuicuis.json
  def index
    @cuicuis = Cuicui.all
  end

  # GET /cuicuis/1
  # GET /cuicuis/1.json
  def show
  end

  # GET /cuicuis/new
  def new
    @cuicui = Cuicui.new
  end

  # GET /cuicuis/1/edit
  def edit
  end

  # POST /cuicuis
  # POST /cuicuis.json
  def create
    @cuicui = Cuicui.new(cuicui_params)

    respond_to do |format|
      if @cuicui.save
        format.html { redirect_to @cuicui, notice: 'Cuicui was successfully created.' }
        format.json { render :show, status: :created, location: @cuicui }
      else
        format.html { render :new }
        format.json { render json: @cuicui.errors, status: :unprocessable_entity }
      end
    end
  end

  # PATCH/PUT /cuicuis/1
  # PATCH/PUT /cuicuis/1.json
  def update
    respond_to do |format|
      if @cuicui.update(cuicui_params)
        format.html { redirect_to @cuicui, notice: 'Cuicui was successfully updated.' }
        format.json { render :show, status: :ok, location: @cuicui }
      else
        format.html { render :edit }
        format.json { render json: @cuicui.errors, status: :unprocessable_entity }
      end
    end
  end

  # DELETE /cuicuis/1
  # DELETE /cuicuis/1.json
  def destroy
    @cuicui.destroy
    respond_to do |format|
      format.html { redirect_to cuicuis_url, notice: 'Cuicui was successfully destroyed.' }
      format.json { head :no_content }
    end
  end

  private

  # Use callbacks to share common setup or constraints between actions.
  def set_cuicui
    @cuicui = Cuicui.find(params[:id])
  end

  # Never trust parameters from the scary internet, only allow the white list through.
  def cuicui_params
    params.require(:cuicui).permit(:content, :user_id)
  end
end
