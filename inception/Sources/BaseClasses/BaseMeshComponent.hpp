#ifndef __BASE_MESH_COMPONENT_HPP__
#define __BASE_MESH_COMPONENT_HPP__
namespace Base
{
    /**
    * @brief ???
    */
    class MeshComponent : public SceneObjectComponent
    {
    public:
        MeshComponent(SceneObjectComponent::wptr parent, const std::string& name);

        ~MeshComponent() override;

        void Init() override;

    protected:
        ///
        uint32_t vertexBufferObject_ = _UI32_MAX;

        ///
        uint32_t indexBufferObject_ = _UI32_MAX;

        ///
        std::vector<Math3D::Vector3f> vertices_; // 26 vertices

        ///
        std::vector<int> indices_; // 48 triangles thus 48 * 3 = 144

        ///
        Base::ShaderProgram::ptr shaderProgram_;
    };
}
#endif // __BASE_MESH_COMPONENT_HPP__