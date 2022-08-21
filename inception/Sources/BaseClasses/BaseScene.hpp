#ifndef __BASE_SCENE_HPP__
#define __BASE_SCENE_HPP__
namespace Base {
    class Scene : public Object
    {
    public:
        using sptr = std::shared_ptr<Scene>;
        using wptr = std::weak_ptr<Scene>;
        using ObjectTree = std::vector<SceneObject::sptr>;

        explicit Scene(const std::string& name);

        ~Scene() override;

        /**
         * @brief Adds object into scene.
         */
        void AddObject(SceneObject::sptr sceneObject);

        /**
        * @brief Calls Update for each object in the scene.
        */
        virtual void Update(float dt);

        /**
         * @brief Returns object tree.
         */
        const ObjectTree& GetObjectTree() const;


        /**
        * @brief Loads the scene content.
        */
        virtual bool Load(const Base::RenderFacility::sptr& renderer, Base::Controller::sptr inputController) = 0;

    protected:
        ObjectTree objectTree_;
    };
}
#endif // __BASE_SCENE_HPP__